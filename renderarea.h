#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType { Astroid, Cycloid, HuygensCycloid, HypoCycloid, Line };

    void setBackgroundColor (QColor color) { mBackgroundColor = color; } //setter
    QColor backgroundColor () const { return mBackgroundColor; } //getter

    void setShapeColor (QColor color) { mShapeColor = color; }
    QColor shapeColor() const { return mShapeColor; }

    void setShape(ShapeType shape) { mShape = shape; on_shape_changed(); }
    ShapeType getshape() const { return mShape; }

    void setScale(float scale) { mScale = scale; repaint(); }
    float scale() const { return mScale; }

    void setIntervalLength(float interval_length) { mIntervalLength = interval_length; repaint(); }
    float intervalLength() const { return mIntervalLength; }

    void setStepCount(int stepCount) { mStepCount = stepCount; repaint(); }
    int stepCount() const { return mStepCount; }

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;
    float mIntervalLength;
    float mScale;
    int mStepCount;

    QPointF compute(float t);   //dispatch function based on mShape's type
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygens(float t);
    QPointF compute_hypo(float t);
    QPointF compute_line(float t);
    void on_shape_changed();

signals:

};

#endif // RENDERAREA_H
