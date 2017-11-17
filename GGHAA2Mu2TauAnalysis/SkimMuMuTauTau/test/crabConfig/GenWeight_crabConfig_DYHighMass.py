from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'DYHighMass_SignalRegion_SEP4_GenWeights'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '../SkimSequence/GenWeightSum.py'

config.Data.inputDataset = '/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISummer16DR80Premix-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext2-v1/AODSIM'
config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 3000 #11500
config.Data.totalUnits = 3000000
config.Data.lumiMask = '/afs/cern.ch/user/k/ktos/SkimDir/CMSSW_8_0_17/src/GGHAA2Mu2TauAnalysis/SkimMuMuTauTau/test/crabConfig/crab_projects/crab_DYHighMass_SignalRegion_SEP4/results/processedLumis.json'
config.Data.outLFNDirBase = '/store/group/phys_higgs/HiggsExo/ktos'
config.Data.publication = True
config.Data.outputDatasetTag = 'DYHighMass_SignalRegion_SEP4_GenWeights'

config.Site.storageSite = 'T2_CH_CERN'
