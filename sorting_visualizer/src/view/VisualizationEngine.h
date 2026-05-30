#ifndef VISUALIZATIONENGINE_H
#define VISUALIZATIONENGINE_H

#include <QWidget>
#include <vector>

class VisualizationEngine : public QWidget {
    Q_OBJECT

private:
    std::vector<int> array;
    int highlightIndex1;
    int highlightIndex2;
    
protected:
    void paintEvent(QPaintEvent* event) override;

public:
    explicit VisualizationEngine(QWidget* parent = nullptr);
    
    void render(const std::vector<int>& arr);
    void highlight(int idx1, int idx2);
    void clearHighlight();
    void setArray(const std::vector<int>& newArray);
    
    std::vector<int> getArray() const { return array; }
};

#endif