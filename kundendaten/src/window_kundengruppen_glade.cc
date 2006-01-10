// generated 2005/12/2 14:03:40 CET by christof@vesta.petig-baender.de
// using glademm V2.10.0.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- kundendaten.glade
// for gtk 2.8.8 and gtkmm 2.8.1
//
// Please modify the corresponding derived classes in ./src/window_kundengruppen.cc


#if defined __GNUC__ && __GNUC__ < 3
#error This program will crash if compiled with g++ 2.x
// see the dynamic_cast bug in the gtkmm FAQ
#endif //
#include "config.h"
/*
 * Standard gettext macros.
 */
#ifdef ENABLE_NLS
#  include <libintl.h>
#  undef _
#  define _(String) dgettext (GETTEXT_PACKAGE, String)
#  ifdef gettext_noop
#    define N_(String) gettext_noop (String)
#  else
#    define N_(String) (String)
#  endif
#else
#  define textdomain(String) (String)
#  define gettext(String) (String)
#  define dgettext(Domain,Message) (Message)
#  define dcgettext(Domain,Message,Type) (Message)
#  define bindtextdomain(Domain,Directory) (Domain)
#  define _(String) (String)
#  define N_(String) (String)
#endif
#include <gtkmmconfig.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
#include <sigc++/compatibility.h>
#include <sigc++/bind.h>
#define GMM_GTKMM_22_24(a,b) b
#else //gtkmm 2.2
#define GMM_GTKMM_22_24(a,b) a
#endif //
#include "window_kundengruppen_glade.hh"
#include <gdk/gdkkeysyms.h>
#include <gtkmm/accelgroup.h>
#include <gtkmm/stockid.h>
#include <gtkmm/label.h>
#include <gtkmm/image.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#include <gtkmm/toolbutton.h>
#else //
#include <gtkmm/button.h>
#endif //
#include <gtkmm/toolbar.h>
#include <gtkmm/box.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#include <gtkmm/toolitem.h>
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
#include <gtkmm/expander.h>
#else //
#include <gtkmm/handlebox.h>
#endif //

window_kundengruppen_glade::window_kundengruppen_glade(
) : Gtk::Window(Gtk::WINDOW_TOPLEVEL)
{  
   
   Gtk::Window *window_kundengruppen = this;
   gmm_data = new GlademmData(get_accel_group());
   
   Gtk::Label *label96 = Gtk::manage(new class Gtk::Label(_("Gruppe")));
   gruppe = new class Optionmenu_Kundengruppe();
   
   Gtk::Image *toolbutton2_img = Gtk::manage(new class Gtk::Image(Gtk::StockID("gtk-new"), Gtk::IconSize(3)));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   Gtk::ToolButton *toolbutton2 = Gtk::manage(new class Gtk::ToolButton(*toolbutton2_img, ""));
#endif //
   Gtk::Image *toolbutton3_img = Gtk::manage(new class Gtk::Image(Gtk::StockID("gtk-delete"), Gtk::IconSize(3)));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   Gtk::ToolButton *toolbutton3 = Gtk::manage(new class Gtk::ToolButton(*toolbutton3_img, ""));
#endif //
   Gtk::Image *toolbutton4_img = Gtk::manage(new class Gtk::Image(Gtk::StockID("gtk-remove"), Gtk::IconSize(3)));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   Gtk::ToolButton *toolbutton4 = Gtk::manage(new class Gtk::ToolButton(*toolbutton4_img, ""));
#endif //
   Gtk::Toolbar *toolbar6 = Gtk::manage(new class Gtk::Toolbar());
   Gtk::HBox *hbox21 = Gtk::manage(new class Gtk::HBox(false, 0));
   kundein = new class SimpleTree(10);
   
   Gtk::Label *label98 = Gtk::manage(new class Gtk::Label(""));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   Gtk::ToolItem *toolitem2 = Gtk::manage(new class Gtk::ToolItem());
#endif //
   Gtk::Image *toolbutton5_img = Gtk::manage(new class Gtk::Image(Gtk::StockID("gtk-go-up"), Gtk::IconSize(3)));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   Gtk::ToolButton *toolbutton5 = Gtk::manage(new class Gtk::ToolButton(*toolbutton5_img, _("Hinzufügen")));
#endif //
   Gtk::Label *label99 = Gtk::manage(new class Gtk::Label(""));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   Gtk::ToolItem *toolitem3 = Gtk::manage(new class Gtk::ToolItem());
#endif //
   Gtk::Toolbar *toolbar7 = Gtk::manage(new class Gtk::Toolbar());
   anderekunden = new class SimpleTree(10);
   
   Gtk::VBox *vbox15 = Gtk::manage(new class Gtk::VBox(false, 0));
   Gtk::Label *label97 = Gtk::manage(new class Gtk::Label(_("Kunden außerhalb der Gruppe")));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   Gtk::Expander *expander1 = Gtk::manage(new class Gtk::Expander());
#else //
   Gtk::HandleBox *expander1 = Gtk::manage(new class Gtk::HandleBox());
#endif //
   Gtk::VBox *vbox14 = Gtk::manage(new class Gtk::VBox(false, 0));
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   toolbar6->append(*toolbutton2);
#else //
   
   
   toolbar6->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("", *toolbutton2_img, Gtk::Toolbar_Helpers::Callback0()));
   Gtk::Button *toolbutton2 = static_cast<Gtk::Button *>(toolbar6->tools().back().get_widget());
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   toolbar6->append(*toolbutton3);
#else //
   
   
   toolbar6->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("", *toolbutton3_img, Gtk::Toolbar_Helpers::Callback0()));
   Gtk::Button *toolbutton3 = static_cast<Gtk::Button *>(toolbar6->tools().back().get_widget());
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   toolbar6->append(*toolbutton4);
#else //
   
   
   toolbar6->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem("", *toolbutton4_img, Gtk::Toolbar_Helpers::Callback0()));
   Gtk::Button *toolbutton4 = static_cast<Gtk::Button *>(toolbar6->tools().back().get_widget());
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   toolbar7->append(*toolitem2);
#else //
   toolbar7->tools().push_back(Gtk::Toolbar_Helpers::Element(*label98));
   
   Gtk::Widget *toolitem2 = toolbar7->tools().back().get_widget();
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   toolbar7->append(*toolbutton5);
#else //
   
   
   toolbar7->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem(_("Hinzufügen"), *toolbutton5_img, Gtk::Toolbar_Helpers::Callback0()));
   Gtk::Button *toolbutton5 = static_cast<Gtk::Button *>(toolbar7->tools().back().get_widget());
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   toolbar7->append(*toolitem3);
#else //
   toolbar7->tools().push_back(Gtk::Toolbar_Helpers::Element(*label99));
   
   Gtk::Widget *toolitem3 = toolbar7->tools().back().get_widget();
#endif //
   label96->set_alignment(0.5,0.5);
   label96->set_padding(0,0);
   label96->set_justify(Gtk::JUSTIFY_LEFT);
   label96->set_line_wrap(false);
   label96->set_use_markup(false);
   label96->set_selectable(false);
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   _tooltips.set_tip(*toolbutton2, _("Neue Gruppe erstellen"), "");
   toolbutton2->set_visible_horizontal(true);
   toolbutton2->set_visible_vertical(true);
   toolbutton2->set_is_important(false);
   toolbutton2->set_homogeneous(true);
   toolbutton2->set_expand(false);
   toolbutton2->set_tooltip(_tooltips, _("Neue Gruppe erstellen"));
#endif //
   toolbutton2_img->show();
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   _tooltips.set_tip(*toolbutton3, _("Gruppe löschen"), "");
   toolbutton3->set_visible_horizontal(true);
   toolbutton3->set_visible_vertical(true);
   toolbutton3->set_is_important(false);
   toolbutton3->set_homogeneous(true);
   toolbutton3->set_expand(false);
   toolbutton3->set_tooltip(_tooltips, _("Gruppe löschen"));
#endif //
   toolbutton3_img->show();
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   _tooltips.set_tip(*toolbutton4, _("ausgewählte Kunden aus Gruppe herausnehmen"), "");
   toolbutton4->set_visible_horizontal(true);
   toolbutton4->set_visible_vertical(true);
   toolbutton4->set_is_important(false);
   toolbutton4->set_homogeneous(true);
   toolbutton4->set_expand(false);
   toolbutton4->set_tooltip(_tooltips, _("ausgewählte Kunden aus Gruppe herausnehmen"));
#endif //
   toolbutton4_img->show();
   toolbar6->set_tooltips(true);
   toolbar6->set_toolbar_style(Gtk::TOOLBAR_ICONS);
   toolbar6->set_orientation(Gtk::ORIENTATION_HORIZONTAL);
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   toolbar6->set_show_arrow(false);
#endif //
   hbox21->pack_start(*label96, Gtk::PACK_SHRINK, 0);
   hbox21->pack_start(*gruppe);
   hbox21->pack_start(*toolbar6, Gtk::PACK_SHRINK, 0);
   label98->set_alignment(0.5,0.5);
   label98->set_padding(0,0);
   label98->set_justify(Gtk::JUSTIFY_LEFT);
   label98->set_line_wrap(false);
   label98->set_use_markup(false);
   label98->set_selectable(false);
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   toolitem2->set_visible_horizontal(true);
   toolitem2->set_visible_vertical(true);
   toolitem2->set_is_important(false);
   toolitem2->set_homogeneous(false);
   toolitem2->set_expand(true);
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   toolitem2->add(*label98);
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   toolbutton5->set_visible_horizontal(true);
   toolbutton5->set_visible_vertical(true);
   toolbutton5->set_is_important(false);
   toolbutton5->set_homogeneous(true);
   toolbutton5->set_expand(false);
#endif //
   toolbutton5_img->show();
   label99->set_alignment(0.5,0.5);
   label99->set_padding(0,0);
   label99->set_justify(Gtk::JUSTIFY_LEFT);
   label99->set_line_wrap(false);
   label99->set_use_markup(false);
   label99->set_selectable(false);
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   toolitem3->set_visible_horizontal(true);
   toolitem3->set_visible_vertical(true);
   toolitem3->set_is_important(false);
   toolitem3->set_homogeneous(false);
   toolitem3->set_expand(true);
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   toolitem3->add(*label99);
#endif //
   toolbar7->set_tooltips(true);
   toolbar7->set_toolbar_style(Gtk::TOOLBAR_ICONS);
   toolbar7->set_orientation(Gtk::ORIENTATION_HORIZONTAL);
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   toolbar7->set_show_arrow(true);
#endif //
   vbox15->pack_start(*toolbar7, Gtk::PACK_SHRINK, 0);
   vbox15->pack_start(*anderekunden);
   label97->set_alignment(0.5,0.5);
   label97->set_padding(0,0);
   label97->set_justify(Gtk::JUSTIFY_LEFT);
   label97->set_line_wrap(false);
   label97->set_use_markup(false);
   label97->set_selectable(false);
   expander1->set_flags(Gtk::CAN_FOCUS);
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   expander1->set_expanded(true);
   expander1->set_spacing(0);
#endif //
   expander1->add(*vbox15);
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   expander1->set_label_widget(*label97);
#endif //
   vbox14->pack_start(*hbox21, Gtk::PACK_SHRINK, 0);
   vbox14->pack_start(*kundein);
   vbox14->pack_start(*expander1);
   window_kundengruppen->set_title(_("Kundengruppen"));
   window_kundengruppen->set_modal(false);
   window_kundengruppen->property_window_position().set_value(Gtk::WIN_POS_NONE);
   window_kundengruppen->set_resizable(true);
   window_kundengruppen->property_destroy_with_parent().set_value(false);
   window_kundengruppen->set_icon(render_icon(Gtk::StockID("gtk-copy"),Gtk::IconSize(Gtk::ICON_SIZE_LARGE_TOOLBAR)));
   window_kundengruppen->add(*vbox14);
   label96->show();
   gruppe->show();
   toolbutton2->show();
   toolbutton3->show();
   toolbutton4->show();
   toolbar6->show();
   hbox21->show();
   kundein->show();
   label98->show();
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   toolitem2->show();
#endif //
   toolbutton5->show();
   label99->show();
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>=3
   toolitem3->show();
#endif //
   toolbar7->show();
   anderekunden->show();
   vbox15->show();
   label97->show();
   expander1->show();
   vbox14->show();
   window_kundengruppen->show();
   gruppe->signal_activate().connect(SigC::slot(*this, &window_kundengruppen_glade::on_gruppenwahl_activate));
   toolbutton2->signal_clicked().connect(SigC::slot(*this, &window_kundengruppen_glade::neu), false);
   toolbutton3->signal_clicked().connect(SigC::slot(*this, &window_kundengruppen_glade::loeschen), false);
   toolbutton4->signal_clicked().connect(SigC::slot(*this, &window_kundengruppen_glade::entfernen), false);
   toolbutton5->signal_clicked().connect(SigC::slot(*this, &window_kundengruppen_glade::add), false);
}

window_kundengruppen_glade::~window_kundengruppen_glade()
{  delete gruppe;
   delete kundein;
   delete anderekunden;
   delete gmm_data;
}
