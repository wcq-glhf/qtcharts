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

#ifndef QPIEMODELMAPPER_P_H
#define QPIEMODELMAPPER_P_H

#include <QtCore/QObject>
#include <QtCharts/QPieModelMapper>

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

QT_CHARTS_BEGIN_NAMESPACE

class QPieSlice;

class QPieModelMapperPrivate : public QObject
{
    Q_OBJECT

public:
    explicit QPieModelMapperPrivate(QPieModelMapper *q);

public Q_SLOTS:
    // for the model
    void modelUpdated(QModelIndex topLeft, QModelIndex bottomRight);
    void modelRowsAdded(QModelIndex parent, int start, int end);
    void modelRowsRemoved(QModelIndex parent, int start, int end);
    void modelColumnsAdded(QModelIndex parent, int start, int end);
    void modelColumnsRemoved(QModelIndex parent, int start, int end);
    void handleModelDestroyed();

    // for the series
    void slicesAdded(QList<QPieSlice *> slices);
    void slicesRemoved(QList<QPieSlice *> slices);
    void sliceLabelChanged();
    void sliceValueChanged();
    void handleSeriesDestroyed();

    void initializePieFromModel();

private:
    QPieSlice *pieSlice(QModelIndex index) const;
    bool isLabelIndex(QModelIndex index) const;
    bool isValueIndex(QModelIndex index) const;
    QModelIndex valueModelIndex(int slicePos);
    QModelIndex labelModelIndex(int slicePos);
    void insertData(int start, int end);
    void removeData(int start, int end);

    void blockModelSignals(bool block = true);
    void blockSeriesSignals(bool block = true);

private:
    QPieSeries *m_series;
    QList<QPieSlice *> m_slices;
    QAbstractItemModel *m_model;
    int m_first;
    int m_count;
    Qt::Orientation m_orientation;
    int m_valuesSection;
    int m_labelsSection;
    bool m_seriesSignalsBlock;
    bool m_modelSignalsBlock;

private:

    QPieModelMapper *q_ptr;
    Q_DECLARE_PUBLIC(QPieModelMapper)
};

QT_CHARTS_END_NAMESPACE

#endif // QPIEMODELMAPPER_P_H
