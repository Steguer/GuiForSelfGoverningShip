#include "PropertiesWindow.hpp"

PropertiesWindow::PropertiesWindow(): QScrollArea()
{
	m_gbox = new QGridLayout();

	auto root = Parsser::readConfigFile();

	vector<std::string> v = root.getMemberNames();

	for(auto &it : v)
	{
		if(root[it].isInt())
		{
			PropLine tmp_widgetItemVect;
			tmp_widgetItemVect.editText = new QLineEdit(QString::number(Parsser::readConfigInt(it)));
			tmp_widgetItemVect.label = new QLabel( QString(it.c_str()));
			m_widgetItem.append(tmp_widgetItemVect);
		}
	}

	int i=0;
	for(auto &it : m_widgetItem)
	{
		m_gbox->addWidget(it.label, i, 0);
		m_gbox->addWidget(it.editText, i, 1);
		++i;
	}

	setAutoFillBackground(true);
	setBackgroundRole(QPalette::Base);

	m_container = new QWidget();
	m_container->setLayout(m_gbox);
	this->setWidget(m_container);
}

PropertiesWindow::~PropertiesWindow()
{
	delete m_gbox;
	delete m_container;
	clearData();
}

void PropertiesWindow::save()
{
	for(auto &it : m_widgetItem)
	{
		Parsser::writeConfig((it.label->text()).toStdString(), (it.editText->text()).toInt());
	}
}

void PropertiesWindow::clearData()
{
	for(auto &it : m_widgetItem)
	{
		delete it.editText;
		delete it.label;
	}
	m_widgetItem.clear();
	
}

void PropertiesWindow::loadData()
{
	clearData();
	auto root = Parsser::readConfigFile();

	vector<string> v = root.getMemberNames();
	for(auto &it : v)
	{
		if(root[it].isInt())
		{
			PropLine tmp_widgetItemVect;
			tmp_widgetItemVect.editText = new QLineEdit(QString::number(Parsser::readConfigInt(it)));
			tmp_widgetItemVect.label = new QLabel( QString(it.c_str()));
			m_widgetItem.append(tmp_widgetItemVect);
		}
	}

	int i=0;
	for(auto &it : m_widgetItem)
	{
		m_gbox->addWidget(it.label, i, 0);
		m_gbox->addWidget(it.editText, i, 1);
		++i;
	}
	m_container = new QWidget();
	m_container->setLayout(m_gbox);
	this->setWidget(m_container);
}