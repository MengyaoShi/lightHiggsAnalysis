from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'DYLowMass_NoIsoDiTau_SEP4_GenWeights'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '../SkimSequence/GenWeightSum.py'

config.Data.inputDataset = '/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISummer16DR80Premix-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v2/AODSIM'
config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 2300
config.Data.totalUnits = 3000000
config.Data.lumiMask = '/afs/cern.ch/user/k/ktos/SkimDir/CMSSW_8_0_17/src/GGHAA2Mu2TauAnalysis/SkimMuMuTauTau/test/crabConfig/crab_projects/crab_DYLowMass_NoIsoDiTau_SEP4/results/processedLumis.json'
config.Data.outLFNDirBase = '/store/group/phys_higgs/HiggsExo/ktos' #'/store/user/ktos/'
config.Data.publication = True
config.Data.outputDatasetTag = 'DYLowMass_NoIsoDiTau_SEP4_GenWeights'

config.Site.storageSite = 'T2_CH_CERN'
