/**
 * @brief Write with the help of QtProject example code editor.
 * @details [long description]
 * @return [description]
 */
#ifndef LINE_SPACE_HPP
#define LINE_SPACE_HPP

#include <QtWidgets>
#include "TextEditor.hpp"

class TextEditor;

class LineSpace: public QWidget
{
public:
	LineSpace(TextEditor* const& txtEditor);
	~LineSpace();

protected:
	void  paintEvent(QPaintEvent *event);

private:
	TextEditor *m_txtEditor;
	
};

#endif