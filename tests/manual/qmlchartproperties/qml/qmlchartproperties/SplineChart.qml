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

import QtQuick 2.0
import QtCharts 2.0

ChartView {
    title: "spline series"
    anchors.fill: parent
    property variant series: splineSeries
    animationOptions: ChartView.SeriesAnimations

    SplineSeries {
        id: splineSeries
        name: "spline 1"
        XYPoint { x: 0; y: 0 }
        XYPoint { x: 1.1; y: 2.1 }
        XYPoint { x: 1.9; y: 3.3 }
        XYPoint { x: 2.1; y: 2.1 }
        XYPoint { x: 2.9; y: 4.9 }
        XYPoint { x: 3.4; y: 3.0 }
        XYPoint { x: 4.1; y: 3.3 }

        pointLabelsFormat: "@xPoint, @yPoint";

        onNameChanged:              console.log("splineSeries.onNameChanged: " + name);
        onVisibleChanged:           console.log("splineSeries.onVisibleChanged: " + visible);
        onOpacityChanged:           console.log(name + ".onOpacityChanged: " + opacity);
        onClicked:                  console.log(name + ".onClicked: " + point.x + ", " + point.y);
        onHovered:                  console.log(name + ".onHovered: " + point.x + ", " + point.y);
        onPointReplaced:            console.log("splineSeries.onPointReplaced: " + index);
        onPointRemoved:             console.log("splineSeries.onPointRemoved: " + index);
        onPointAdded:               console.log("splineSeries.onPointAdded: " + series.at(index).x + ", " + series.at(index).y);
        onColorChanged:             console.log("splineSeries.onColorChanged: " + color);
        onWidthChanged:             console.log("splineSeries.onWidthChanged: " + width);
        onStyleChanged:             console.log("splineSeries.onStyleChanged: " + style);
        onCapStyleChanged:          console.log("splineSeries.onCapStyleChanged: " + capStyle);
        onCountChanged:             console.log("splineSeries.onCountChanged: " + count);
        onPointLabelsVisibilityChanged:  console.log("splineSeries.onPointLabelsVisibilityChanged: "
                                                     + visible);
        onPointLabelsFormatChanged:      console.log("splineSeries.onPointLabelsFormatChanged: "
                                                     + format);
        onPointLabelsFontChanged:        console.log("splineSeries.onPointLabelsFontChanged: "
                                                     + font.family);
        onPointLabelsColorChanged:       console.log("splineSeries.onPointLabelsColorChanged: "
                                                     + color);
        onPointLabelsClippingChanged:    console.log("splineSeries.onPointLabelsClippingChanged: "
                                                     + clipping);
        onPressed:          console.log(name + ".onPressed: " + point.x + ", " + point.y);
        onReleased:         console.log(name + ".onReleased: " + point.x + ", " + point.y);
        onDoubleClicked:    console.log(name + ".onDoubleClicked: " + point.x + ", " + point.y);
    }

    SplineSeries {
        name: "spline 2"
        XYPoint { x: 1.1; y: 1.1 }
        XYPoint { x: 1.9; y: 2.3 }
        XYPoint { x: 2.1; y: 1.1 }
        XYPoint { x: 2.9; y: 3.9 }
        XYPoint { x: 3.4; y: 2.0 }
        XYPoint { x: 4.1; y: 2.3 }
        onClicked:                  console.log(name + ".onClicked: " + point.x + ", " + point.y);
        onHovered:                  console.log(name + ".onHovered: " + point.x + ", " + point.y);
        onPressed:          console.log(name + ".onPressed: " + point.x + ", " + point.y);
        onReleased:         console.log(name + ".onReleased: " + point.x + ", " + point.y);
        onDoubleClicked:    console.log(name + ".onDoubleClicked: " + point.x + ", " + point.y);
    }
}
