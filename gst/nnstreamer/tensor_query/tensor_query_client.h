/* SPDX-License-Identifier: LGPL-2.1-only */
/**
 * Copyright (C) 2021 Samsung Electronics Co., Ltd.
 *
 * @file    tensor_query_client.h
 * @date    09 Jul 2021
 * @brief   GStreamer plugin to handle tensor query client
 * @author  Junhwan Kim <jejudo.kim@samsung.com>
 * @see     http://github.com/nnstreamer/nnstreamer
 * @bug     No known bugs
 *
 */
#ifndef __GST_TENSOR_QUERY_CLIENT_H__
#define __GST_TENSOR_QUERY_CLIENT_H__

#include <gst/gst.h>
#include <gio/gio.h>
#include <tensor_common.h>
#include <nnstreamer-edge.h>

G_BEGIN_DECLS

#define GST_TYPE_TENSOR_QUERY_CLIENT \
  (gst_tensor_query_client_get_type())
#define GST_TENSOR_QUERY_CLIENT(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_TENSOR_QUERY_CLIENT,GstTensorQueryClient))
#define GST_TENSOR_QUERY_CLIENT_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_TENSOR_QUERY_CLIENT,GstTensorQueryClientClass))
#define GST_IS_TENSOR_QUERY_CLIENT(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_TENSOR_QUERY_CLIENT))
#define GST_IS_TENSOR_QUERY_CLIENT_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_TENSOR_QUERY_CLIENT))
#define GST_TENSOR_QUERY_CLIENT_CAST(obj) ((GstTensorQueryClient *)(obj))

typedef struct _GstTensorQueryClient GstTensorQueryClient;
typedef struct _GstTensorQueryClientClass GstTensorQueryClientClass;

/**
 * @brief GstTensorQueryClient data structure.
 */
struct _GstTensorQueryClient
{
  GstElement element; /**< parent object */
  GstPad *sinkpad; /**< sink pad */
  GstPad *srcpad; /**< src pad */

  gboolean silent; /**< True if logging is minimized */
  gchar *in_caps_str;

  guint timeout; /**< timeout value (in ms) to wait message from server */

  /* Query-hybrid feature */
  gchar *topic; /**< Main operation such as 'object_detection' or 'image_segmentation' */
  gchar *host;
  guint16 port;
  gchar *dest_host;
  guint16 dest_port;

  nns_edge_connect_type_e connect_type;
  nns_edge_h edge_h;
  GAsyncQueue *msg_queue;
};

/**
 * @brief GstTensorQueryClientClass data structure.
 */
struct _GstTensorQueryClientClass
{
  GstElementClass parent_class; /**< parent class */
};

GType gst_tensor_query_client_get_type (void);

G_END_DECLS
#endif /* __GST_TENSOR_QUERY_CLIENT_H__ */
