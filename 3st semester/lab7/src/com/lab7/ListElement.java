package com.lab7;

public class ListElement {
    private ListElement nextEl;
    private TFigure figure;

    public ListElement(TFigure figure) {
        this.figure = figure;
    }

    public ListElement getNextEl() {
        return nextEl;
    }

    public void setNextEl(ListElement nextEl) {
        this.nextEl = nextEl;
    }

    public TFigure getFigure() {
        return figure;
    }

    public void setFigure(TFigure figure) {
        this.figure = figure;
    }
}
