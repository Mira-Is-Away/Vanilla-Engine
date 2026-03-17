/**
 * @file vnl_status.h
 * 
 * Definition of the status codes used throughout the engine.
 * 
 * @author Henry R
 * @date 26-02-28
 */

#ifndef VANILLA_MISC_VNL_STATUS_H_
#define VANILLA_MISC_VNL_STATUS_H_

typedef enum VnlStatus {
    FAILURE = 0,
    SUCCESS = 1,
    WARNING = 2
} VnlStatus;

#endif