#include "TextEditor.hpp"

TextEditor::TextEditor()
{
	m_lineSpace = new LineSpace(this);

	connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineSpaceWidth(int)));
	connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineSpace(QRect,int)));

	updateLineSpaceWidth(0);

	m_name = "newFile";
	m_file = new QUrl("");


	m_highlighter = new Highlighter(this->document());
}

TextEditor::TextEditor(std::string name): TextEditor()
{
	m_name = QString(name.c_str());
	m_file = new QUrl(QString(name.c_str()));
}

TextEditor::TextEditor(QUrl path): TextEditor()
{
	std::cout<<"file name is "<< path.fileName().toStdString()<<std::endl;
	m_file = new QUrl(path);
	QFile file(path.path());
	if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
	{
		std::cout<<"Open File error"<<std::endl;		
	}
	else
	{
		QString fileContent(file.readAll());
		insertPlainText(fileContent);
	}
	m_name = path.fileName();
}

TextEditor::~TextEditor()
{
	delete m_lineSpace;
	delete m_highlighter;
	delete m_file;
}

void TextEditor::updateLineSpaceWidth(int)
{
	 int digits = 1;
     int max = qMax(1, blockCount());
     while (max >= 10) {
         max /= 10;
         ++digits;
     }

    m_space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

	setViewportMargins(m_space, 0, 0, 0);
}

void TextEditor::updateLineSpace(QRect const& rect, int const& dy)
{
	if (dy)
	{
         m_lineSpace->scroll(0, dy);
	}
    else
    {
        m_lineSpace->update(0, rect.y(), m_lineSpace->width(), rect.height());
    }
}

void TextEditor::resizeEvent(QResizeEvent *e)
{
	QPlainTextEdit::resizeEvent(e);

	QRect rec = contentsRect();
	m_lineSpace->setGeometry(QRect(rec.left(), rec.top(), m_space, rec.height()));
}

void TextEditor::lineSpacePaint(QPaintEvent *event)
{
	QPainter painter(m_lineSpace);
	//Set the background to lightGray to be sure of the color. 
	painter.fillRect(event->rect(), Qt::lightGray);

	QTextBlock block = firstVisibleBlock();
	int blockNumber = block.blockNumber();
	int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
	int bottom = top + (int) blockBoundingRect(block).height();

	while (block.isValid()) 
	{
	    if (block.isVisible())
	    {
	        QString number = QString::number(blockNumber + 1);
	        painter.setPen(Qt::black);
	        painter.drawText(0, top, m_lineSpace->width(), fontMetrics().height(), Qt::AlignRight, number);
	    }

	    block = block.next();
	    top = bottom;
	    bottom = top + (int) blockBoundingRect(block).height();
	    ++blockNumber;
	}
}

int TextEditor::getSpace()
{
	return m_space;
}