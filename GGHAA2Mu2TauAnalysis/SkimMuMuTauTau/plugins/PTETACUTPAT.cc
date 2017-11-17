// -*- C++ -*-
//
// Package:    temp/PTETACUTPAT
// Class:      PTETACUTPAT
// 
/**\class PTETACUTPAT PTETACUTPAT.cc temp/PTETACUTPAT/plugins/PTETACUTPAT.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Mengyao Shi
//         Created:  Wed, 25 Nov 2015 16:25:51 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/stream/EDFilter.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/StreamID.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/PatCandidates/interface/Muon.h"
//
//
// class declaration
//

class PTETACUTPAT : public edm::EDFilter {
   public:
      explicit PTETACUTPAT(const edm::ParameterSet&);
      ~PTETACUTPAT();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

   private:
      virtual void beginJob() override;
      virtual bool filter(edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;
      
      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

      // ----------member data ---------------------------
 edm::EDGetTokenT<edm::View<pat::Muon> > muonTag_;
 unsigned int minNumObjsToPassFilter_;
 double Eta_;
 double Pt_;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
PTETACUTPAT::PTETACUTPAT(const edm::ParameterSet& iConfig):
 muonTag_(consumes<edm::View<pat::Muon> >(iConfig.getParameter<edm::InputTag>("muonTag"))),
 minNumObjsToPassFilter_(iConfig.getParameter<unsigned int>("minNumObjsToPassFilter")),
 Eta_(iConfig.getParameter<double>("Eta")),
 Pt_(iConfig.getParameter<double>("Pt"))
{

   //now do what ever initialization is needed
   produces<std::vector<pat::Muon> >();
}


PTETACUTPAT::~PTETACUTPAT()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called on each new Event  ------------
bool
PTETACUTPAT::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  unsigned int nPassingMuons=0;
  edm::Handle<edm::View<pat::Muon> > recoObjs;
  iEvent.getByToken(muonTag_, recoObjs);
  std::auto_ptr<std::vector<pat::Muon> > muonColl(new std::vector<pat::Muon> );
  for (edm::View<pat::Muon>::const_iterator iRecoObj = recoObjs->begin(); iRecoObj != recoObjs->end();  ++iRecoObj) 
  {
    if( (fabs(iRecoObj->eta())<Eta_ || Eta_==-1) && iRecoObj->pt()>Pt_)
    {
      muonColl->push_back(*iRecoObj);
      nPassingMuons++;
    }
  }
  
  iEvent.put(muonColl);

  return (nPassingMuons >= minNumObjsToPassFilter_);
}
   

// ------------ method called once each job just before starting event loop  ------------
void 
PTETACUTPAT::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
PTETACUTPAT::endJob() {
}

// ------------ method called when starting to processes a run  ------------
/*
void
PTETACUTPAT::beginRun(edm::Run const&, edm::EventSetup const&)
{ 
}
*/
 
// ------------ method called when ending the processing of a run  ------------
/*
void
PTETACUTPAT::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method called when starting to processes a luminosity block  ------------
/*
void
PTETACUTPAT::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method called when ending the processing of a luminosity block  ------------
/*
void
PTETACUTPAT::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/
 
// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
PTETACUTPAT::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}
//define this as a plug-in
DEFINE_FWK_MODULE(PTETACUTPAT);

