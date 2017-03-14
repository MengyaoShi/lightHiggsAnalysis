from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'SignalH125a5_NoIsoDiTau_NoMVA_FEB9'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '../SkimSequence/TestRegionsSkim_Crab.py'

config.Data.inputDataset = '/SUSYGluGluToHToAA_AToMuMu_AToTauTau_M-5_TuneCUETP8M1_13TeV_madgraph_pythia8/RunIISpring16DR80-premix_withHLT_80X_mcRun2_asymptotic_v14-v1/AODSIM'
config.Data.inputDBS = 'global'
config.Data.outLFNDirBase = '/store/group/phys_higgs/HiggsExo/ktos'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 40
config.Data.totalUnits = 3000000
config.Data.publication = True
config.Data.outputDatasetTag = 'SignalH125a5_NoIsoDiTau_NoMVA_FEB9'

config.Site.storageSite = 'T2_CH_CERN'