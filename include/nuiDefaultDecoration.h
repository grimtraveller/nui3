/*
  NUI3 - C++ cross-platform GUI framework for OpenGL based applications
  Copyright (C) 2002-2003 Sebastien Metrot

  licence: see nui3/LICENCE.TXT
*/


#pragma once

#include "nui.h"


class nuiWidget;
class nuiSimpleContainer;
class nuiMainWindow;
class nuiMessageBox;
class nuiTabView;

typedef nuiFastDelegate::FastDelegate1<nuiWidget*> nuiDecorationDelegate;


class nuiDefaultDecoration
{
public:
  
  nuiDefaultDecoration();
  ~nuiDefaultDecoration();
  
  static void Init();

  // special case
  static void MainWindow(nuiMainWindow* pWindow);
  static void Dialog(nuiSimpleContainer* pCont);
//  static void DialogSelectFile(nuiSimpleContainer* pCont);
  static void MessageBox(nuiMessageBox* pBox);
  static void TabView_Tab(nuiTabView* pView, nuiWidget* pTab);
  static void TabView_Contents(nuiTabView* pView, nuiWidget* pContents);
  
protected:
  
  static void InitColors();
  static void InitSelection();
  static void InitMaps();
  static void InitIcons();
  

  static void Window(nuiWidget* pWidget);
  static void BackgroundPane(nuiWidget* pWidget);
  
  static void Label(nuiWidget* pWidget);
  static void EditText(nuiWidget* pWidget);
  static void EditLine(nuiWidget* pWidget);

  static void SplitterHandle(nuiWidget* pWidget);

  static void TitledPane(nuiWidget* pWidget);
  static void FolderPane(nuiWidget* pWidget);

  static void Button(nuiWidget* pWidget);
  static void RadioButton(nuiWidget* pWidget);
  static void CloseButton(nuiWidget* pWidget);
  static void ToggleButton(nuiWidget* pWidget);
  
  static void ComboBox(nuiWidget* pWidget);

  // dialogs
  static void Dialog_Title(nuiWidget* pWidget);
//  static void DialogSelectFile_Title(nuiWidget* pWidget);
  static void Dialog_EditLine(nuiWidget* pWidget);
  static void MessageBox_Title(nuiWidget* pWidget);


  // file selector
  static void FileSelector_FolderView(nuiWidget* pWidget);
  static void FileSelector_InfoView(nuiWidget* pWidget);
  static void FileSelector_FolderLabel(nuiWidget* pWidget);
  static void FileSelector_VolumeIcon(nuiWidget* pWidget);
  static void FileSelector_FolderIcon(nuiWidget* pWidget);
  static void FileSelector_TreeView(nuiWidget* pWidget);
  static void FileSelector_TreeFolderLabel(nuiWidget* pWidget);
  static void FileSelector_TreeFileLabel(nuiWidget* pWidget);
  static void FileSelector_TreeFolderIcon(nuiWidget* pWidget);
  static void FileSelector_TreeFileIcon(nuiWidget* pWidget);
  


};