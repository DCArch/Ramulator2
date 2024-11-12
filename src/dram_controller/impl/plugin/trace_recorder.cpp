#include <vector>
#include <unordered_map>
#include <limits>
#include <filesystem>

#include <fmt/core.h>

#include "base/base.h"
#include "dram_controller/controller.h"
#include "dram_controller/plugin.h"

namespace Ramulator {

class TraceRecorder : public IControllerPlugin, public Implementation {
  RAMULATOR_REGISTER_IMPLEMENTATION(IControllerPlugin, TraceRecorder, "TraceRecorder", "CounterBasedTRR.")
  private:
    IDRAM* m_dram;

    std::filesystem::path m_trace_path; 

    Clk_t m_clk = 0;

  public:
    void init() override { 
      m_trace_path = param<std::string>("path").desc("Path to the trace file").required();
      auto parent_path = m_trace_path.parent_path();
      std::filesystem::create_directories(parent_path);
      if (!(std::filesystem::exists(parent_path) && std::filesystem::is_directory(parent_path))) {
        throw ConfigurationError("Invalid path to trace file: {}", parent_path.string());
      }
    };

    void setup(IFrontEnd* frontend, IMemorySystem* memory_system) override {
      m_ctrl = cast_parent<IDRAMController>();
      m_dram = m_ctrl->m_dram;
    };

    void update(bool request_found, ReqBuffer::iterator& req_it) override {
      m_clk++;
    };

};

}       // namespace Ramulator
