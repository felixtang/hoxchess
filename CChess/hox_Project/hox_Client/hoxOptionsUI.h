/////////////////////////////////////////////////////////////////////////////
// Name:        hoxOptionsUI.h
// Purpose:     
// Author:      Huy Phan
// Modified by: 
// Created:     3/9/2009 6:58:33 AM
// RCS-ID:      
// Copyright:   Copyright 2007-2009 Huy Phan  <huyphan@playxiangqi.com>
// Licence:     GNU General Public License v3
/////////////////////////////////////////////////////////////////////////////

#ifndef _HOXOPTIONSUI_H_
#define _HOXOPTIONSUI_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/propdlg.h"
#include "wx/valgen.h"
#include "wx/clrpicker.h"
////@end includes

#include "MyApp.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxColourPickerCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_HOXOPTIONSAPP 10018
#define m_panelMain 10002
#define ID_CHECKBOX_SOUND 10003
#define m_checkBox2 10004
#define ID_STATIC_TEXT_LANG 10005
#define ID_CHOICE_LANGUAGE 10006
#define m_panelBoard 10007
#define m_staticText31 10008
#define ID_COLOR_BACKGROUND 10009
#define m_staticText4 10010
#define ID_COLOR_FOREGROUND 10011
#define m_staticText5 10012
#define ID_PIECE_SET_CHOICES 10013
#define ID_PANEL_PIECE_PREVIEW 10014
#define m_panelAI 10015
#define m_staticText3 10016
#define ID_LISTBOX_ENGINES 10000
#define SYMBOL_HOXOPTIONSUI_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_HOXOPTIONSUI_TITLE _("Options")
#define SYMBOL_HOXOPTIONSUI_IDNAME ID_HOXOPTIONSAPP
#define SYMBOL_HOXOPTIONSUI_SIZE wxDefaultSize
#define SYMBOL_HOXOPTIONSUI_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * hoxOptionsUI class declaration
 */

class hoxOptionsUI: public wxPropertySheetDialog
{    
    DECLARE_DYNAMIC_CLASS( hoxOptionsUI )
    DECLARE_EVENT_TABLE()

public:
    hoxLanguageInfoVector m_langList;
    wxLanguage   m_language;
    wxString     m_sBgColor;
    wxString     m_sFgColor;
    wxString     m_sPiece;
    wxString     m_sDefaultAI;

    /// Constructors
    hoxOptionsUI();
    hoxOptionsUI( wxWindow* parent, wxWindowID id = SYMBOL_HOXOPTIONSUI_IDNAME, const wxString& caption = SYMBOL_HOXOPTIONSUI_TITLE, const wxPoint& pos = SYMBOL_HOXOPTIONSUI_POSITION, const wxSize& size = SYMBOL_HOXOPTIONSUI_SIZE, long style = SYMBOL_HOXOPTIONSUI_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_HOXOPTIONSUI_IDNAME, const wxString& caption = SYMBOL_HOXOPTIONSUI_TITLE, const wxPoint& pos = SYMBOL_HOXOPTIONSUI_POSITION, const wxSize& size = SYMBOL_HOXOPTIONSUI_SIZE, long style = SYMBOL_HOXOPTIONSUI_STYLE );

    /// Destructor
    ~hoxOptionsUI();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin hoxOptionsUI event handler declarations

    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_CHOICE_LANGUAGE
    void OnChoiceLanguageSelected( wxCommandEvent& event );

    /// wxEVT_COLOURPICKER_CHANGED event handler for ID_COLOR_BACKGROUND
    void OnColorBackgroundColourPickerChanged( wxColourPickerEvent& event );

    /// wxEVT_COLOURPICKER_CHANGED event handler for ID_COLOR_FOREGROUND
    void OnColorForegroundColourPickerChanged( wxColourPickerEvent& event );

    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_PIECE_SET_CHOICES
    void OnPieceSetChoicesSelected( wxCommandEvent& event );

    /// wxEVT_PAINT event handler for ID_PANEL_PIECE_PREVIEW
    void OnPaint( wxPaintEvent& event );

    /// wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_LISTBOX_ENGINES
    void OnListboxEnginesSelected( wxCommandEvent& event );

////@end hoxOptionsUI event handler declarations

////@begin hoxOptionsUI member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end hoxOptionsUI member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin hoxOptionsUI member variables
    wxCheckBox* m_checkBoxSound;
    wxChoice* m_choiceLanguage;
    wxColourPickerCtrl* m_colorPickerBackground;
    wxColourPickerCtrl* m_colorPickerForeground;
    wxChoice* m_pieceSetChoices;
    wxPanel* m_panelPiecePreview;
    wxListBox* m_listBoxEngines;
public:
    bool m_bSound;
    bool m_bWelcome;
////@end hoxOptionsUI member variables

private:
    void _InitLanguageChoices();
    void _InitPieceSetChoices();
    void _InitAIChoices();
    wxArrayString _loadAvailablePieceSets() const;
    void _DrawPiecePreview( wxPanel*      panel,
                            const wxPoint p1,
                            const wxPoint p2 );
    void _DrawOnePieceAt( wxDC&          dc,
                          hoxPieceType   pieceType,
                          hoxColor       pieceColor,
                          const wxPoint& pos );

};

#endif
    // _HOXOPTIONSUI_H_