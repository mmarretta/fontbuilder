#include <QDebug>
#include <QGraphicsView>
#include <QMessageBox>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QJsonArray>

#include "customjsonexporter.h"
#include "../fontconfig.h"


CustomJsonExporter::CustomJsonExporter(QObject *parent)
	: AbstractExporter(parent)
{
	setExtension("jfnt");
}

bool CustomJsonExporter::Export(QByteArray& out)
{
	QJsonDocument doc;
	QJsonObject obj;
	QJsonArray jsymbols;

	QString name = QString("%1 %2").arg(fontConfig()->family()).arg(fontConfig()->style());

	obj.insert("name", QJsonValue(name));
	obj.insert("size", QJsonValue((int)fontConfig()->size()));
	obj.insert("file", QJsonValue(texFilename().toLower()));

	foreach(const Symbol& c, symbols())
	{
		QJsonObject jSymbol;
		jSymbol.insert("id", (int)c.id);
		jSymbol.insert("width", (int)c.placeW);
		jSymbol.insert("xoffset", (int)c.placeX);
		jsymbols.insert(jsymbols.end(), QJsonValue(jSymbol));
	}

	obj.insert("symbols", QJsonValue(jsymbols));
	doc.setObject(obj);

	out = doc.toJson();
	return true;
}

AbstractExporter* CustomJsonExporterFactoryFunc (QObject* parent)
{
	return new CustomJsonExporter(parent);
}
