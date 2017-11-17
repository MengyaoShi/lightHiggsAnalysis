#!/bin/bash
#parse arguments
if [ $# -ne 2 ]
    then
    echo "Usage: GIVE ME A NEW TAG and then a Old Tag!"
    exit 0
fi

new_tag="${1}"
old_tag="${2}"

export SCRAM_ARCH=slc6_amd64_gcc481
cd /afs/cern.ch/user/k/ktos/SkimDir/CMSSW_8_0_17/src
eval `scramv1 runtime -sh`
cd -
source ~/SETENV.sh

DATE=`date +TIME_%H-%M-%S__DATE_%y-%m-%d`
FILENAME="CRAB_SUBMIT_HLT_ALL_${new_tag}_${DATE}.txt"

sed -i "s|${old_tag}|${new_tag}|g" crabConf*

echo "SIGNAL"
crab submit crabConfig_SignalH125a19.py >> $FILENAME
echo "" >> $FILENAME
crab submit crabConfig_SignalH125a5.py >> $FILENAME
echo "" >> $FILENAME
crab submit crabConfig_SignalH125a9.py >> $FILENAME
echo "" >> $FILENAME
crab submit crabConfig_SignalH750a9.py >> $FILENAME
echo "" >> $FILENAME

#echo "DATA"
#crab submit crabConfig_TestRegions.py >> $FILENAME

