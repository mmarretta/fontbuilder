// Exporter for Sparrow Framework
// http://www.sparrow-framework.org/

#ifndef CUSTOMJSONEXPORTER_H
#define CUSTOMJSONEXPORTER_H

#include "../abstractexporter.h"

class CustomJsonExporter : public AbstractExporter
{
    Q_OBJECT
public:
	explicit CustomJsonExporter(QObject *parent = 0);

    virtual bool Export(QByteArray& out);
signals:

public slots:

};

#endif // CUSTOMJSONEXPORTER_H
