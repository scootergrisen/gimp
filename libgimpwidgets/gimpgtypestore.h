/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-1997 Peter Mattis and Spencer Kimball
 *
 * gimpgtypestore.c
 * Copyright (C) 2004  Sven Neumann <sven@gimp.org>
 * Copyright (C) 2015 Jehan <jehan@girinstud.io>
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#if !defined (__GIMP_WIDGETS_H_INSIDE__) && !defined (GIMP_WIDGETS_COMPILATION)
#error "Only <libgimpwidgets/gimpwidgets.h> can be included directly."
#endif

#ifndef __GIMP_GTYPE_STORE_H__
#define __GIMP_GTYPE_STORE_H__

G_BEGIN_DECLS


/**
 * GimpGTypeStoreColumns:
 * @GIMP_GTYPE_STORE_VALUE:       the GType value
 * @GIMP_GTYPE_STORE_LABEL:       a human-readable label
 * @GIMP_GTYPE_STORE_ICON_NAME:   an icon name
 * @GIMP_GTYPE_STORE_PIXBUF:      a #GdkPixbuf
 * @GIMP_GTYPE_STORE_USER_DATA:   arbitrary user data
 * @GIMP_GTYPE_STORE_NUM_COLUMNS: the number of columns
 * @GIMP_GTYPE_STORE_STOCK_ID:    compat alias for @GIMP_GTYPE_STORE_ICON_NAME
 *
 * The column types of #GimpGTypeStore.
 **/
typedef enum
{
  GIMP_GTYPE_STORE_VALUE,
  GIMP_GTYPE_STORE_LABEL,
  GIMP_GTYPE_STORE_ICON_NAME,
  GIMP_GTYPE_STORE_PIXBUF,
  GIMP_GTYPE_STORE_USER_DATA,
  GIMP_GTYPE_STORE_NUM_COLUMNS,

  /* deprecated */
  GIMP_GTYPE_STORE_STOCK_ID = GIMP_GTYPE_STORE_ICON_NAME
} GimpGTypeStoreColumns;


#define GIMP_TYPE_GTYPE_STORE            (gimp_gtype_store_get_type ())
#define GIMP_GTYPE_STORE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIMP_TYPE_GTYPE_STORE, GimpGTypeStore))
#define GIMP_GTYPE_STORE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GIMP_TYPE_GTYPE_STORE, GimpGTypeStoreClass))
#define GIMP_IS_GTYPE_STORE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIMP_TYPE_GTYPE_STORE))
#define GIMP_IS_GTYPE_STORE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GIMP_TYPE_GTYPE_STORE))
#define GIMP_GTYPE_STORE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GIMP_TYPE_GTYPE_STORE, GimpGTypeStoreClass))


typedef struct _GimpGTypeStoreClass  GimpGTypeStoreClass;

struct _GimpGTypeStore
{
  GtkListStore  parent_instance;

  /*< private >*/
  GtkTreeIter  *empty_iter;
};

struct _GimpGTypeStoreClass
{
  GtkListStoreClass  parent_class;

  /* Padding for future expansion */
  void (* _gimp_reserved1) (void);
  void (* _gimp_reserved2) (void);
  void (* _gimp_reserved3) (void);
  void (* _gimp_reserved4) (void);
};


GType          gimp_gtype_store_get_type        (void) G_GNUC_CONST;

GtkListStore * gimp_gtype_store_new             (void);

gboolean       gimp_gtype_store_lookup_by_value (GtkTreeModel  *model,
                                                 GType          value,
                                                 GtkTreeIter   *iter);


G_END_DECLS

#endif  /* __GIMP_GTYPE_STORE_H__ */
