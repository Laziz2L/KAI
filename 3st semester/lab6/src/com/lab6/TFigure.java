package com.lab6;

import javafx.scene.canvas.GraphicsContext;

public abstract class TFigure {
    private double x;
    private double y;

    public TFigure(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public void Show(boolean sh, GraphicsContext gc) {
        if(sh) gc.fillText("Фигура", x, y);
        else gc.fill();
    }

    final public void MoveTo(double dx, double dy, GraphicsContext gc) {
        this.Show(false, gc);
        this.x += dx;
        this.y += dy;
        this.Show(true, gc);
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }
}
