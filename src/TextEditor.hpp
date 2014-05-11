#ifndef TEXT_EDITOR_HPP
#define TEXT_EDITOR_HPP

#include <QtWidgets>
#include <iostream>
#include "LineSpace.hpp"
#include "Highlighter.hpp"

class TextEditor: public QPlainTextEdit
{
Q_OBJECT

public:
	TextEditor();
	TextEditor(std::string name);
	TextEditor(QUrl path);
	~TextEditor();

	void lineSpacePaint(QPaintEvent *event);

	int getSpace();
	QString getFileName();
	void saveFile(QUrl* const& path = nullptr);

public slots:
	void updateLineSpaceWidth(int);
	void updateLineSpace(QRect const&, int const&);

protected:
	void resizeEvent(QResizeEvent *e);

private:
	QWidget *m_lineSpace;
	int m_space;
	Highlighter *m_highlighter;
	QUrl *m_filePath;
	QString m_name;
	
};

#endif