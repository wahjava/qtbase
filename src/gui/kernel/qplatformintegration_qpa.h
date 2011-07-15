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

#ifndef QPLATFORMINTEGRATION_H
#define QPLATFORMINTEGRATION_H

#include <QtGui/qwindowdefs.h>
#include <QtGui/qplatformpixmap_qpa.h>
#include <QtGui/qplatformscreen_qpa.h>
#include <QtGui/qsurfaceformat.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Gui)

class QPlatformWindow;
class QWindow;
class QPlatformBackingStore;
class QPlatformFontDatabase;
class QPlatformClipboard;
class QPlatformNativeInterface;
class QPlatformPrinterSupport;
class QPlatformDrag;
class QPlatformGLContext;
class QGuiGLFormat;
class QAbstractEventDispatcher;
class QPlatformInputContext;

class Q_GUI_EXPORT QPlatformIntegration
{
public:
    enum Capability {
        ThreadedPixmaps = 1,
        OpenGL = 2
    };

    virtual ~QPlatformIntegration() { }

    virtual bool hasCapability(Capability cap) const;

// GraphicsSystem functions
    virtual QPlatformPixmap *createPlatformPixmap(QPlatformPixmap::PixelType type) const = 0;
    virtual QPlatformWindow *createPlatformWindow(QWindow *window) const = 0;
    virtual QPlatformBackingStore *createPlatformBackingStore(QWindow *window) const = 0;
    virtual QPlatformGLContext *createPlatformGLContext(const QSurfaceFormat &format, QPlatformGLContext *share) const;

// Window System functions
    virtual QList<QPlatformScreen *> screens() const = 0;
    virtual void moveToScreen(QWindow *window, int screen) {Q_UNUSED(window); Q_UNUSED(screen);}
    virtual bool isVirtualDesktop() { return false; }
    virtual QPixmap grabWindow(WId window, int x, int y, int width, int height) const;

// Event dispatcher:
    virtual QAbstractEventDispatcher *createEventDispatcher() const = 0;

//Deeper window system integrations
    virtual QPlatformFontDatabase *fontDatabase() const;
#ifndef QT_NO_CLIPBOARD
    virtual QPlatformClipboard *clipboard() const;
#endif
#ifndef QT_NO_DRAGANDDROP
    virtual QPlatformDrag *drag() const;
#endif
    virtual QPlatformInputContext *inputContext() const;

// Access native handles. The window handle is already available from Wid;
    virtual QPlatformNativeInterface *nativeInterface() const;

    virtual QPlatformPrinterSupport *printerSupport() const;
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QPLATFORMINTEGRATION_H
