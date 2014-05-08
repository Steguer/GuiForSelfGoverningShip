#ifndef WIDGET_ITEM_HPP
#define WIDGET_ITEM_HPP

#include <QtWidgets>

template <typename T, typename U>
class WidgetItem: public QWidget
{
public:
	WidgetItem()
	{
		m_hbox = new QGridLayout();
		m_propertieLabel = new QLabel("salut");
		m_propertieEdit = new T();

		m_hbox->addWidget(m_propertieLabel, 0, 0);
		m_hbox->addWidget(m_propertieEdit, 0, 1);

		this->setLayout(m_hbox);
	}

	WidgetItem(QString labelNaame, U data): WidgetItem()
	{
		m_propertieLabel->setText(labelNaame);
		m_propertieEdit->setText(QString(data));
	}

private:
	QGridLayout *m_hbox;
	QLabel *m_propertieLabel;
	T *m_propertieEdit;
	
};

#endif