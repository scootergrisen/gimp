/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-1997 Peter Mattis and Spencer Kimball
 *
 * gimpgtypecombobox.h
 * Copyright (C) 2004  Sven Neumann <sven@gimp.org>
 * Copyright (C) 2015  Jehan <jehan@girinstud.io>
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

#ifndef __GIMP_GTYPE_COMBO_BOX_H__
#define __GIMP_GTYPE_COMBO_BOX_H__

G_BEGIN_DECLS


#define GIMP_TYPE_GTYPE_COMBO_BOX            (gimp_gtype_combo_box_get_type ())
#define GIMP_GTYPE_COMBO_BOX(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIMP_TYPE_GTYPE_COMBO_BOX, GimpGTypeComboBox))
#define GIMP_GTYPE_COMBO_BOX_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GIMP_TYPE_GTYPE_COMBO_BOX, GimpGTypeComboBoxClass))
#define GIMP_IS_GTYPE_COMBO_BOX(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIMP_TYPE_GTYPE_COMBO_BOX))
#define GIMP_IS_GTYPE_COMBO_BOX_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GIMP_TYPE_GTYPE_COMBO_BOX))
#define GIMP_GTYPE_COMBO_BOX_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GIMP_TYPE_GTYPE_COMBO_BOX, GimpGTypeComboBoxClass))


typedef struct _GimpGTypeComboBoxClass  GimpGTypeComboBoxClass;

struct _GimpGTypeComboBox
{
  GtkComboBox       parent_instance;

  /*< private >*/
  gpointer          priv;

  /* Padding for future expansion (should have gone to the class) */
  void (* _gimp_reserved2) (void);
  void (* _gimp_reserved3) (void);
  void (* _gimp_reserved4) (void);
};

struct _GimpGTypeComboBoxClass
{
  GtkComboBoxClass  parent_class;
};


typedef  gboolean (* GimpGTypeSensitivityFunc)    (GType             value,
                                                   gpointer          data);



GType         gimp_gtype_combo_box_get_type        (void) G_GNUC_CONST;

GtkWidget   * gimp_gtype_combo_box_new             (const gchar       *first_label,
                                                    GType              first_value,
                                                    ...) G_GNUC_NULL_TERMINATED;
GtkWidget   * gimp_gtype_combo_box_new_valist      (const gchar       *first_label,
                                                    GType              first_value,
                                                    va_list            values);

void          gimp_gtype_combo_box_prepend         (GimpGTypeComboBox *combo_box,
                                                    ...);
void          gimp_gtype_combo_box_append          (GimpGTypeComboBox *combo_box,
                                                    ...);

gboolean      gimp_gtype_combo_box_set_active      (GimpGTypeComboBox *combo_box,
                                                    GType              value);
gboolean      gimp_gtype_combo_box_get_active      (GimpGTypeComboBox *combo_box,
                                                    GType             *value);

gulong        gimp_gtype_combo_box_connect         (GimpGTypeComboBox *combo_box,
                                                    GType              value,
                                                    GCallback          callback,
                                                    gpointer           data);

void          gimp_gtype_combo_box_set_label       (GimpGTypeComboBox *combo_box,
                                                    const gchar       *label);
const gchar * gimp_gtype_combo_box_get_label       (GimpGTypeComboBox *combo_box);

void          gimp_gtype_combo_box_set_sensitivity (GimpGTypeComboBox        *combo_box,
                                                    GimpGTypeSensitivityFunc  func,
                                                    gpointer                  data,
                                                    GDestroyNotify            destroy);


G_END_DECLS

#endif  /* __GIMP_GTYPE_COMBO_BOX_H__ */
