// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "core/optimizer/graph_transformer.h"

namespace onnxruntime {

/**
@Class EmbedLayerNormFusion

Rewrite graph fusing embeddings and mask processing into one node.

*/
class EmbedLayerNormFusion : public GraphTransformer {
 public:
  EmbedLayerNormFusion(const std::unordered_set<std::string>& compatible_execution_providers = {}) noexcept
      : GraphTransformer("EmbedLayerNormFusion", compatible_execution_providers) {}

  Status ApplyImpl(Graph& graph, bool& modified, int graph_level, const logging::Logger& logger) const override;
 private:
  float DEFAULT_EMBED_EPSILON = 1e-12f;
};

}  // namespace onnxruntime
