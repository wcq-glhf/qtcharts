/******************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Charts module.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
******************************************************************************/

//  W A R N I N G
//  -------------
//
// This file is not part of the Qt Chart API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef CHARTCONFIG_H
#define CHARTCONFIG_H

#include <QtCharts/QChartGlobal>

QT_CHARTS_BEGIN_NAMESPACE

class ChartConfig
{
private:
    ChartConfig() {
        m_instance = this;
    }
public:
    static ChartConfig *instance() {
        if (!m_instance) {
            m_instance = new ChartConfig();
        }
        return m_instance;
    }

private:
    static ChartConfig *m_instance;
};


ChartConfig *ChartConfig::m_instance = 0;

QT_CHARTS_END_NAMESPACE

#endif
