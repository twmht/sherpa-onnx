// sherpa-onnx/csrc/offline-speech-denoiser-model-config.h
//
// Copyright (c)  2025  Xiaomi Corporation
#ifndef SHERPA_ONNX_CSRC_OFFLINE_SPEECH_DENOISER_MODEL_CONFIG_H_
#define SHERPA_ONNX_CSRC_OFFLINE_SPEECH_DENOISER_MODEL_CONFIG_H_

#include <string>

#include "sherpa-onnx/csrc/offline-speech-denoiser-gtcrn-model-config.h"
#include "sherpa-onnx/csrc/parse-options.h"

namespace sherpa_onnx {

struct OfflineSpeechDenoiserModelConfig {
  OfflineSpeechDenoiserGtcrnModelConfig gtcrn;

  int32_t num_threads = 1;
  bool debug = false;
  std::string provider = "cpu";

  OfflineSpeechDenoiserModelConfig() = default;

  OfflineSpeechDenoiserModelConfig(
      const OfflineSpeechDenoiserGtcrnModelConfig &gtcrn, int32_t num_threads,
      bool debug, const std::string &provider)
      : gtcrn(gtcrn),
        num_threads(num_threads),
        debug(debug),
        provider(provider) {}

  void Register(ParseOptions *po);
  bool Validate() const;

  std::string ToString() const;
};

}  // namespace sherpa_onnx

#endif  // SHERPA_ONNX_CSRC_OFFLINE_SPEECH_DENOISER_MODEL_CONFIG_H_
