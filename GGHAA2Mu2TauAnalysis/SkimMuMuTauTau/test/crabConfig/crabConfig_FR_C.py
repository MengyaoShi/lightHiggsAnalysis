from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'SignalRegion_SEP18_lumiTree_C'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '../SkimSequence/MultiTrigger_FakeRate.py' #_HLT2.py'

config.Data.inputDataset = '/SingleMuon/Run2016C-23Sep2016-v1/AOD'
config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 175 
config.Data.totalUnits = 3000000
config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt'
config.Data.outLFNDirBase = '/store/group/phys_higgs/HiggsExo/ktos/' #'/store/user/ktos/' #'/store/group/phys_higgs/HiggsExo/ktos/' #'/store/user/ktos/'
config.Data.publication = True
config.Data.outputDatasetTag = 'SignalRegion_SEP18_lumiTree_C'

config.Site.storageSite = 'T2_CH_CERN'
