/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtWebEngine module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef BROWSER_CONTEXT_ADAPTER_H
#define BROWSER_CONTEXT_ADAPTER_H

#include "qtwebenginecoreglobal.h"

#include <QScopedPointer>
#include <QSharedData>

class BrowserContextQt;
class WebEngineVisitedLinksManager;

// Make a QSharedData if we need to open arbitrary BrowserContextAdapter beyond the defaults.
class QWEBENGINE_EXPORT BrowserContextAdapter // : public QSharedData
{
public:
    virtual ~BrowserContextAdapter();

    static BrowserContextAdapter* defaultContext();
    static BrowserContextAdapter* offTheRecordContext();

    WebEngineVisitedLinksManager *visitedLinksManager();

    BrowserContextQt *browserContext();
    bool isOffTheRecord() const { return m_offTheRecord; }
    QString dataPath() const;
    QString cachePath() const;

protected:
    explicit BrowserContextAdapter(bool offTheRecord = false);

private:
    bool m_offTheRecord;
    QScopedPointer<BrowserContextQt> m_browserContext;
    QScopedPointer<WebEngineVisitedLinksManager> m_visitedLinksManager;
    friend class WebEngineContext;

    Q_DISABLE_COPY(BrowserContextAdapter)
};

#endif // BROWSER_CONTEXT_ADAPTER_H