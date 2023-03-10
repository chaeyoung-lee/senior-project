/**
 * @file mat_logger.h
 * @brief Declaration file for the MatLogger class which records runtime
 * zero-forcing matrices into csv files. Enabled or disabled by cmake.
 */

#ifndef MAT_LOGGER_H_
#define MAT_LOGGER_H_

#include <array>
#include <cstdint>
#include <string>

#include "armadillo"
#include "csv_logger.h"

namespace CsvLog {

constexpr size_t kFrames = 1000;
constexpr size_t kSCs = 304;
constexpr size_t kBSAnts = 8;
constexpr size_t kUEAnts = 1;

class MatLogger : public CsvLogger {
 public:
  MatLogger(const std::string& radio_id, size_t mat_log_id);
  bool UpdateMatBuf(const size_t frame_id, const size_t sc_id,
                    const arma::cx_fmat& mat_in);
  ~MatLogger();

 private:
  void SaveMatBuf();
#if defined(ENABLE_MAT_LOG)
  std::array<
      std::array<std::array<std::array<arma::cx_float, kUEAnts>, kBSAnts>,
                 kSCs>,
      kFrames>
      mat_buffer_;
#endif
};  //Class MatLogger;

}  //namespace CsvLog
#endif  //MAT_LOGGER_H_