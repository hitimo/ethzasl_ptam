// -*- c++ -*-
// Copyright 2008 Isis Innovation Limited

#ifndef __CAMERACALIBRATOR_H
#define __CAMERACALIBRATOR_H
#include "CalibImage.h"
#include <gvars3/gvars3.h>
#include <vector>
#include "GLWindow2.h"
#include "ptam/RosNode.h"
#include <ros/ros.h>
#include <sensor_msgs/Image.h>

class CameraCalibrator
{
public:
  CameraCalibrator();
  void Run();
  
protected:
  void Reset();
//  void HandleFrame(CVD::Image<CVD::byte> imFrame);
//  static void MainLoopCallback(void* pvUserData);
//  void MainLoopStep();
  
  GLWindow2 mGLWindow;
  ATANCamera mCamera;
  bool mbDone;

  std::vector<CalibImage> mvCalibImgs;
  void OptimizeOneStep();
  
  bool mbGrabNextFrame;

  GVars3::gvar3<int> mgvnOptimizing;
  GVars3::gvar3<int> mgvnShowImage;
  GVars3::gvar3<int> mgvnDisableDistortion;

  double mdMeanPixelError;

  CVD::Image<CVD::byte> mCurrentImage;
  image_transport::Subscriber mImageSub;
  bool mNewImage;
  void imageCallback(const sensor_msgs::ImageConstPtr & img);

  void GUICommandHandler(std::string sCommand, std::string sParams);
  static void GUICommandCallBack(void* ptr, std::string sCommand, std::string sParams);
};

#endif
