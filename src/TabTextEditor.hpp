#ifndef TAB_TEXT_EDITOR_HPP
#define TAB_TEXT_EDITOR_HPP

#include <QtWidgets>
#include <unordered_map>
#include "TextEditor.hpp"

class TabTextEditor: public QWidget
{
Q_OBJECT

public:
	TabTextEditor();
	~TabTextEditor();

public slots:
	void closeTab(int);
	void closeCurrentTab();
	void makeTextEditor();
	void makeTextEditor(QString);

private:
	QTabWidget *m_tab;
	QList<TextEditor*> m_txtEdit;
	QHBoxLayout *m_hbox;
};

#endif