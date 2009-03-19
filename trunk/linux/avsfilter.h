/***************************************************************************
                          AVSfilter.cpp  -  description
                             -------------------
    begin                : 28-04-2008
    copyright            : (C) 2008 by fahr
    email                : fahr at inbox dot ru
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef AVSFILTER__
#define AVSFILTER__

typedef struct
{
  char **pipename;
  int hpipe;
  int flags;
} AVS_PIPES;

#define PIPE_LOADER_READ 0
#define PIPE_LOADER_WRITE 1
#define PIPE_FILTER_WRITE 2

#define CMD_PIPE_NUM (PIPE_FILTER_WRITE+1)

typedef struct
{
  ADM_filename *avs_script;
  ADM_filename *avs_loader;
  time_t script_ftime[2]; // script timestamp
  uint32_t pipe_timeout;
} AVS_PARAM;

typedef struct
{
  AVS_PARAM _param;
  AVS_PIPES avs_pipes[CMD_PIPE_NUM];
  ADV_Info input_info, temp_info;
  void *next_wine_loader;
} WINE_LOADER;

typedef struct
{
  AVS_PIPES *avs_pipes;
  FILE *pfile;
} TPARSER;

class  ADMVideoAVSfilter:public AVDMGenericVideoStream
{
protected:
  AVDMGenericVideoStream *in;
  VideoCache *vidCache;
  virtual char *printConf(void);
  uint32_t in_frame_sz, out_frame_sz;
  char *pipe_loader_read, *pipe_loader_write;
  char *pipe_filter_write;
  virtual bool SetParameters(AVS_PARAM *newparam);
  WINE_LOADER *wine_loader;
  AVS_PARAM *_param;
  bool wine_load, avs_load;
public:
  ADMVideoAVSfilter( AVDMGenericVideoStream *in,CONFcouple *setup);
  virtual ~ADMVideoAVSfilter();
  virtual uint8_t getFrameNumberNoAlloc(uint32_t frame, uint32_t *len,
                                        ADMImage *data,uint32_t *flags);
  virtual uint8_t configure( AVDMGenericVideoStream *instream);
  uint8_t getCoupledConf( CONFcouple **couples);
};

/**
 * Class to cleanup all data after filter unload completely
 */
class AVSTerminate
{
public:
  AVSTerminate() {printf("Terminate class is calling in start\n");}
  virtual ~AVSTerminate();
};

#endif
