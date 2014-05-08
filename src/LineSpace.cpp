#include "LineSpace.hpp"

LineSpace::LineSpace(TextEditor* const& txtEditor): QWidget(txtEditor)
{
	m_txtEditor = txtEditor;
}

LineSpace::~LineSpace()
{

}

void LineSpace::paintEvent(QPaintEvent *event)
{
	m_txtEditor->lineSpacePaint(event);
}
