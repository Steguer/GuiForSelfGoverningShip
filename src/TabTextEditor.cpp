#include "TabTextEditor.hpp"

TabTextEditor::TabTextEditor(): QWidget()
{
	m_tab = new QTabWidget();
	m_tab->setTabsClosable(true);

	m_hbox = new QHBoxLayout();
	m_hbox->addWidget(m_tab);

	this->setLayout(m_hbox);

	QObject::connect(m_tab, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
}

TabTextEditor::~TabTextEditor()
{
	delete m_tab;
	delete m_hbox;
	for(auto &tab : m_txtEdit)
	{
		delete tab;
	}
}

void TabTextEditor::makeTextEditor(QString tabName)
{
	m_txtEdit.append(new TextEditor(tabName.toStdString()));
	m_tab->addTab(m_txtEdit.last(), tabName);
}

void TabTextEditor::makeTextEditor()
{
	makeTextEditor("newFile");
}

void TabTextEditor::makeTextEditor(QUrl path)
{
	m_txtEdit.append(new TextEditor(path));
	m_tab->addTab(m_txtEdit.last(), path.fileName());
}

void TabTextEditor::closeTab(int index)
{
	m_tab->removeTab(index);
	delete m_txtEdit.at(index);
	m_txtEdit.removeAt(index);
}

void TabTextEditor::closeCurrentTab()
{
	int index = m_tab->currentIndex();
	m_tab->removeTab(index);
	m_txtEdit.removeAt(index);
}

void TabTextEditor::saveCurrentFile()
{
	int index = m_tab->currentIndex();
	m_txtEdit.at(index)->saveFile();
	m_tab->setTabText(index, m_txtEdit.at(index)->getFileName());
}

void TabTextEditor::saveCurrentFileAs()
{
	int index = m_tab->currentIndex();
	m_txtEdit.at(index)->saveFile(new QUrl(QFileDialog::getSaveFileName(this)));
	m_tab->setTabText(index, m_txtEdit.at(index)->getFileName());
}