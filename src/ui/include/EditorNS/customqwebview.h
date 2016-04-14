#ifndef CUSTOMQWEBVIEW_H
#define CUSTOMQWEBVIEW_H

#include <QWheelEvent>

#ifdef USE_QTWEBENGINE
    #include <QWebEngineView>
    #define WEBVIEWNAME QWebEngineView
#else
    #include <QWebView>
    #define WEBVIEWNAME QWebView
#endif

namespace EditorNS
{

    class CustomQWebView : public WEBVIEWNAME
    {
        Q_OBJECT
        QString jsStringEscape(QString str) const;
    public:
        explicit CustomQWebView(QWidget *parent = 0);
        QVariant evaluateJavaScript(const QString &expr);
        void connectJavaScriptObject(QString name, QObject *obj);
    signals:
        void mouseWheel(QWheelEvent *ev);
        void JavascriptEvaluated();
        void urlsDropped(QList<QUrl> urls);

    public slots:

    protected:
        void wheelEvent(QWheelEvent *ev);
        void keyPressEvent(QKeyEvent *ev);
        void dropEvent(QDropEvent *ev);
    };

}

#endif // CUSTOMQWEBVIEW_H
