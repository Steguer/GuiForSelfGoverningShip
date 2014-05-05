#include "PathConfigLeaf.hpp"

PathConfigLeaf::PathConfigLeaf()
{
	m_gbox = new QGridLayout;

	m_scriptPathLabel = new QLabel("Script path");

	m_editPyScriptPath = new QLineEdit();

	m_exploreScriptPathButton = new QPushButton("...");

	m_gbox->addWidget(m_scriptPathLabel, 0, 0);
	m_gbox->addWidget(m_editPyScriptPath, 0, 1);
	m_gbox->addWidget(m_exploreScriptPathButton, 0, 2);

	this->setLayout(m_gbox);

	QObject::connect(m_exploreScriptPathButton, SIGNAL(clicked()), this, SLOT(collectScriptPath()));
}

PathConfigLeaf::~PathConfigLeaf()
{
	delete m_gbox;
	delete m_scriptPathLabel;
	delete m_editPyScriptPath;
	delete m_exploreScriptPathButton;
}

void PathConfigLeaf::collectScriptPath()
{
	m_scriptPath = QFileDialog::getExistingDirectory(this);
	m_editPyScriptPath->setText(m_scriptPath);
}

QString PathConfigLeaf::getScriptPath()
{
	return m_editPyScriptPath->text();
}

void PathConfigLeaf::setSciptPath(QString const& path)
{
	m_editPyScriptPath->setText(path);
}