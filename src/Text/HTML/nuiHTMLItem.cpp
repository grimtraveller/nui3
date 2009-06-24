/*
 NUI3 - C++ cross-platform GUI framework for OpenGL based applications
 Copyright (C) 2002-2003 Sebastien Metrot
 
 licence: see nui3/LICENCE.TXT
 */


#include "nui.h"
#include "nuiHTMLItem.h"

/////////////////class nuiHTMLItem
nuiHTMLItem::nuiHTMLItem(nuiHTMLNode* pNode, bool Inline)
: mpNode(pNode), mInline(Inline), mEndTag(false), mLineBreak(false)
{
  ForceLineBreak(pNode->GetTagType() == nuiHTMLNode::eTag_BR);
}

nuiHTMLItem::~nuiHTMLItem()
{
}

void nuiHTMLItem::Draw(nuiDrawContext* pContext)
{
}

void nuiHTMLItem::CallDraw(nuiDrawContext* pContext)
{
  pContext->PushMatrix();
  pContext->Translate(mRect.Left(), mRect.Top());
  //pContext->DrawRect(GetRect().Size(), eStrokeShape);
  Draw(pContext);
  pContext->PopMatrix();
}

void nuiHTMLItem::Layout(nuiHTMLContext& rContext)
{
  bool set = !IsEndTag();
  switch (mpNode->GetTagType())
  {
  case nuiHTML::eTag_I:
  case nuiHTML::eTag_EM:
    {
      rContext.mFont.SetItalic(set, 1.0f);
    }
    break;
  case nuiHTML::eTag_B:
  case nuiHTML::eTag_STRONG:
    {
      rContext.mFont.SetBold(set, 1.0f);
    }
    break;
  case nuiHTML::eTag_U:
    {
      rContext.mUnderline = set;
    }
    break;
  case nuiHTML::eTag_STRIKE:
    {
      rContext.mUnderline = set;
    }
    break;
  case nuiHTML::eTag_A:
    {
      rContext.mUnderline = set;
      if (set)
        rContext.mTextFgColor = nuiColor(0, 0, 200);
      else
        rContext.mTextFgColor = nuiColor(0, 0, 0);
    }
    break;
  }
}

const nuiRect& nuiHTMLItem::GetRect() const
{
  return mRect;
}

void nuiHTMLItem::SetRect(const nuiRect& rRect)
{
  //printf("nuiHTMLItem::SetRect %ls\n", rRect.GetValue().GetChars());
  mRect = rRect;
}

#undef max

const nuiRect& nuiHTMLItem::GetIdealRect() const
{
  return mIdealRect;
}

void nuiHTMLItem::MoveTo(float x, float y)
{
  mRect.MoveTo(x, y);
}

void nuiHTMLItem::SetWidth(float w)
{
  mRect.SetWidth(w);
}

void nuiHTMLItem::SetHeight(float h)
{
  mRect.SetHeight(h);
}

void nuiHTMLItem::SetParent(nuiHTMLBox* pBox)
{
  mpParent = pBox;
}

nuiHTMLBox* nuiHTMLItem::GetParent() const
{
  return mpParent;
}

float nuiHTMLItem::GetAscender() const
{
  return mIdealRect.GetHeight();
}

float nuiHTMLItem::GetDescender() const
{
  return 0;
}

bool nuiHTMLItem::IsInline() const
{
  return mInline;
}

void nuiHTMLItem::SetInline(bool set)
{
  mInline = set;
}

bool nuiHTMLItem::IsEndTag() const
{
  return mEndTag;
}

void nuiHTMLItem::SetEndTag(bool set)
{
  mEndTag = set;
}

bool nuiHTMLItem::IsLineBreak() const
{
  return mLineBreak;
}

void nuiHTMLItem::ForceLineBreak(bool s)
{
  mLineBreak = s;
}

nglString nuiHTMLItem::GetAbsoluteURL(const nglString& rString) const
{
  nglString url(rString);
  int32 colon = url.Find(':');
  if (colon > 0)
  {
    // complete url link
  }
  else if (url[0] == '/')
  {
    // Site absolute
    nglString str(mpNode->GetSourceURL());
    int32 col = str.Find(_T("://"));
    if (col > 0)
    {
      int32 end = str.Find('/', col + 3);
      if (end)
        url = str.Extract(0, end) + url;
    }
  }
  else
  {
    // Site relative
    nglString str(mpNode->GetSourceURL());
    int32 end = str.FindLast(_T('/'));
    if (end)
    {
      url = str.Extract(0, end) + url;
    }
    else
    {
      url = str + _T("/") + url;
    }
  }

  return url;
}
