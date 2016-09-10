#include "nodelist.h"

NodeList::NodeList(QWidget *parent)
    : QTreeWidget(parent)
{
    make();
}

void NodeList::make()
{
        // populate data from sql table

        QList<QTreeWidgetItem*> items;
        for( int i=0; i<10; i++ )
        {
            QStringList col;

            col << QString("item: %1").arg(i);
            col << "DUA"; col << "TIGA";

    //        QTreeWidgetItem *item = new QTreeWidgetItem( (QTreeWidget*)0, QStringList( QString("item: %1").arg(i) ) );
            QTreeWidgetItem *item = new QTreeWidgetItem( (QTreeWidget*)0, col );
            items.append(item);
        }

        m_columnCount = 3;
        setColumnCount(m_columnCount);

        addTopLevelItems(items);

        //m_dB->getRecord4()
}
