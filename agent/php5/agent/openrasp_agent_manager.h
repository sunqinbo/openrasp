/*
 * Copyright 2017-2018 Baidu Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _OPENRASP_AGENT_MANAGER_H_
#define _OPENRASP_AGENT_MANAGER_H_

#include "mm/shm_manager.h"
#include "openrasp_ctrl_block.h"
#include <sys/prctl.h>

#define OPENRASP_SET_PROC_NAME(name) prctl(PR_SET_NAME, (name), 0, 0, 0)

namespace openrasp
{

class ShmManager;
class OpenraspCtrlBlock;

class OpenraspAgentManager
{
  public:
    OpenraspAgentManager(ShmManager *mm);

    void supervisor_run();

    int startup();
    int shutdown();

  private:
    int _create_share_memory();
    int _destroy_share_memory();

    int _agent_startup();
    int _process_agent_startup();

    int _write_local_plugin_md5_to_shm();

  private:
    ShmManager *_mm;
    OpenraspCtrlBlock *_agent_ctrl_block;
    std::string _root_dir;
};

} // namespace openrasp

#endif