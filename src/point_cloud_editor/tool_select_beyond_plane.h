// Copyright 2017 ETH Zürich, Thomas Schöps
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.


#pragma once

#include <Eigen/Core>
#include <Eigen/StdVector>

#include "point_cloud_editor/render_widget.h"

namespace point_cloud_editor {

// Tool for selecting all points behind a plane (as seen from the render camera).
class BeyondPlaneSelectionTool : public Tool {
 public:
  BeyondPlaneSelectionTool(RenderWidget* render_widget);
  
  void PerformSelection(
      const std::vector<Eigen::Vector3f, Eigen::aligned_allocator<Eigen::Vector3f>>& points);
  
  void SetLimitSelectionToVisible(bool enable);
  
  virtual bool mousePressEvent(QMouseEvent* /*event*/) override;
  virtual bool mouseMoveEvent(QMouseEvent* /*event*/) override;
  virtual bool mouseReleaseEvent(QMouseEvent* /*event*/) override;
  virtual bool keyPressEvent(QKeyEvent* /*event*/) override;
  
  virtual void paintEvent(QPainter* /*painter*/) override;

 private:
  std::vector<Eigen::Vector3f, Eigen::aligned_allocator<Eigen::Vector3f>> points_;
  
  bool limit_selection_to_visible_;
};

}
