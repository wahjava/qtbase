/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include <private/qpaintengine_s60_p.h>
#include <private/qpixmap_s60_p.h>
#include <private/qt_s60_p.h>
#include <private/qvolatileimage_p.h>

QT_BEGIN_NAMESPACE

class QS60PaintEnginePrivate : public QRasterPaintEnginePrivate
{
public:
    QS60PaintEnginePrivate() {}
};

QS60PaintEngine::QS60PaintEngine(QPaintDevice *device, QS60PlatformPixmap *data)
    : QRasterPaintEngine(*(new QS60PaintEnginePrivate), device), handle(data)
{
}

bool QS60PaintEngine::begin(QPaintDevice *device)
{
    Q_D(QS60PaintEngine);

    if (handle->classId() == QPlatformPixmap::RasterClass) {
        handle->beginDataAccess();
        bool ret = QRasterPaintEngine::begin(device);
        // Make sure QPaintEngine::paintDevice() returns the proper device.
        // QRasterPaintEngine changes pdev to QImage in case of RasterClass QPlatformPixmap
        // which is incorrect in Symbian.
        d->pdev = device;
        return ret;
    }

    return QRasterPaintEngine::begin(device);
}

bool QS60PaintEngine::end()
{
    if (handle->classId() == QPlatformPixmap::RasterClass) {
        bool ret = QRasterPaintEngine::end();
        handle->endDataAccess();
        return ret;
    }
    return QRasterPaintEngine::end();
}

void QS60PaintEngine::drawPixmap(const QPointF &p, const QPixmap &pm)
{
    if (pm.handle()->classId() == QPlatformPixmap::RasterClass) {
        QS60PlatformPixmap *srcData = static_cast<QS60PlatformPixmap *>(pm.handle());
        srcData->beginDataAccess();
        QRasterPaintEngine::drawPixmap(p, pm);
        srcData->endDataAccess();
    } else {
        void *nativeData = pm.handle()->toNativeType(QPlatformPixmap::VolatileImage);
        if (nativeData) {
            QVolatileImage *img = static_cast<QVolatileImage *>(nativeData);
            img->beginDataAccess();
            QRasterPaintEngine::drawImage(p, img->imageRef());
            img->endDataAccess(true);
        } else {
            QRasterPaintEngine::drawPixmap(p, pm);
        }
    }
}

void QS60PaintEngine::drawPixmap(const QRectF &r, const QPixmap &pm, const QRectF &sr)
{
    if (pm.handle()->classId() == QPlatformPixmap::RasterClass) {
        QS60PlatformPixmap *srcData = static_cast<QS60PlatformPixmap *>(pm.handle());
        srcData->beginDataAccess();
        QRasterPaintEngine::drawPixmap(r, pm, sr);
        srcData->endDataAccess();
    } else {
        void *nativeData = pm.handle()->toNativeType(QPlatformPixmap::VolatileImage);
        if (nativeData) {
            QVolatileImage *img = static_cast<QVolatileImage *>(nativeData);
            img->beginDataAccess();
            QRasterPaintEngine::drawImage(r, img->imageRef(), sr);
            img->endDataAccess(true);
        } else {
            QRasterPaintEngine::drawPixmap(r, pm, sr);
        }
    }
}

void QS60PaintEngine::drawTiledPixmap(const QRectF &r, const QPixmap &pm, const QPointF &sr)
{
    if (pm.handle()->classId() == QPlatformPixmap::RasterClass) {
        QS60PlatformPixmap *srcData = static_cast<QS60PlatformPixmap *>(pm.handle());
        srcData->beginDataAccess();
        QRasterPaintEngine::drawTiledPixmap(r, pm, sr);
        srcData->endDataAccess();
    } else {
        QRasterPaintEngine::drawTiledPixmap(r, pm, sr);
    }
}

void QS60PaintEngine::prepare(QImage *image)
{
    QRasterBuffer *buffer = d_func()->rasterBuffer.data();
    if (buffer)
        buffer->prepare(image);
}

QT_END_NAMESPACE
