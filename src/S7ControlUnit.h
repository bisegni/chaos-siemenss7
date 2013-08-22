/*
 *	S7ControlUnit.h
 *	!CHOAS
 *	Created by Bisegni Claudio.
 *
 *    	Copyright 2013 INFN, National Institute of Nuclear Physics
 *
 *    	Licensed under the Apache License, Version 2.0 (the "License");
 *    	you may not use this file except in compliance with the License.
 *    	You may obtain a copy of the License at
 *
 *    	http://www.apache.org/licenses/LICENSE-2.0
 *
 *    	Unless required by applicable law or agreed to in writing, software
 *    	distributed under the License is distributed on an "AS IS" BASIS,
 *    	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    	See the License for the specific language governing permissions and
 *    	limitations under the License.
 */

#ifndef __ControlUnitTest__S7ControlUnit__
#define __ControlUnitTest__S7ControlUnit__

#include <chaos/cu_toolkit/ControlManager/RTAbstractControlUnit.h>

using namespace std;
using namespace chaos;
using namespace boost;
using namespace boost::posix_time;

namespace cu_driver = chaos::cu::driver_manager::driver;

typedef struct t_plc_variable{
	int db_num;
	int start;
	int byte_count;
	chaos::DataType::DataType type;
} t_plc_variable;

class S7ControlUnit : public chaos::cu::RTAbstractControlUnit {
    string deviceID;
	string definitionParamter;
protected:
    //define dataset
    void unitDefineActionAndDataset()throw(CException);
    
	//defin control unit driver
	void unitDefineDriver(std::vector<chaos::cu::driver_manager::driver::DrvRequestInfo>& neededDriver);
	
    // init contorl unit
    void unitInit() throw(CException);
    
	//start contor unit
    void unitStart() throw(CException);
    
	//intervalled scheduled method
    void unitRun() throw(CException);
    
    //stop contor unit
    void unitStop() throw(CException);
    
    //deinit
    void unitDeinit() throw(CException);
public:
    /*
     Construct a new CU with an identifier
     */
    S7ControlUnit(string _deviceID, string _definitionParamter);
	
	/*
     Base destructor
     */
	~S7ControlUnit();
	
	static bool checkDefinitionparam(string& defParam);
};


#endif /* defined(__ControlUnitTest__S7ControlUnit__) */
