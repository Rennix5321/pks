#include "VisualizationEngine.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <algorithm>

VisualizationEngine::VisualizationEngine(QWidget* parent)
    : QWidget(parent)
    , highlightIndex1(-1)
    , highlightIndex2(-1) {
    setMinimumHeight(400);
    setStyleSheet("background-color: #1e1e2e;");
}

void VisualizationEngine::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    if (array.empty()) return;
    
    int width = this->width();
    int height = this->height();
    int n = array.size();
    int barWidth = std::max(2, width / n - 2);
    
    int maxVal = *std::max_element(array.begin(), array.end());
    if (maxVal == 0) maxVal = 1;
    
    // Рисуем сетку
    painter.setPen(QPen(QColor(50, 50, 70), 1));
    for (int y = 100; y <= height - 20; y += 100) {
        painter.drawLine(10, height - y, width - 10, height - y);
    }
    
    for (int i = 0; i < n; i++) {
        int barHeight = static_cast<int>((static_cast<double>(array[i]) / maxVal) * (height - 80));
        int x = i * (barWidth + 2) + 2;
        int y = height - barHeight - 25;
        
        // Выбор цвета
        if (i == highlightIndex1 || i == highlightIndex2) {
            painter.setBrush(QBrush(QColor(255, 100, 50)));
            painter.setPen(QPen(QColor(255, 150, 100), 1));
        } else {
            int intensity = 100 + (array[i] * 100 / maxVal);
            painter.setBrush(QBrush(QColor(70, 130, 200 + intensity / 4)));
            painter.setPen(QPen(QColor(150, 200, 255), 1));
        }
        
        painter.drawRect(x, y, barWidth, barHeight);
        
        // Текст значения
        painter.setPen(QPen(QColor(0, 0, 0), 2));
        QFont font = painter.font();
        font.setPointSize(9);
        font.setBold(true);
        painter.setFont(font);
        painter.drawText(x + barWidth / 2 - 8, y - 3, QString::number(array[i]));
        
        painter.setPen(QPen(QColor(255, 255, 255), 0));
        painter.drawText(x + barWidth / 2 - 8, y - 3, QString::number(array[i]));
    }
}

void VisualizationEngine::render(const std::vector<int>& arr) {
    array = arr;
    update();
}

void VisualizationEngine::highlight(int idx1, int idx2) {
    highlightIndex1 = idx1;
    highlightIndex2 = idx2;
    update();
}

void VisualizationEngine::clearHighlight() {
    highlightIndex1 = -1;
    highlightIndex2 = -1;
    update();
}

void VisualizationEngine::setArray(const std::vector<int>& newArray) {
    array = newArray;
    clearHighlight();
    update();
}