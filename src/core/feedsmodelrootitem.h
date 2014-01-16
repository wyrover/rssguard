#ifndef FEEDSMODELROOTITEM_H
#define FEEDSMODELROOTITEM_H

#include <QIcon>

#include <QDateTime>


// Represents ROOT item of FeedsModel.
// NOTE: This class is derived to add functionality for
// all other non-root items of FeedsModel.
class FeedsModelRootItem {
  public:
    // Describes the kind of the item.
    enum Kind {
      RootItem  = 1001,
      Feed      = 1002,
      Category  = 1003
    };

    // Constructors and destructors.
    explicit FeedsModelRootItem(FeedsModelRootItem *parent_item = NULL);
    virtual ~FeedsModelRootItem();

    // Basic operations.
    inline virtual FeedsModelRootItem *parent() const {
      return m_parentItem;
    }

    inline virtual void setParent(FeedsModelRootItem *parent_item) {
      m_parentItem = parent_item;
    }

    inline virtual FeedsModelRootItem *child(int row) {
      return m_childItems.value(row);
    }

    inline virtual int childCount() const {
      return m_childItems.size();
    }

    inline virtual int columnCount() const {
      // FeedsModel offers exactly two columns.
      return 2;
    }

    inline virtual void appendChild(FeedsModelRootItem *child) {
      m_childItems.append(child);
      child->setParent(this);
    }

    virtual int row() const;
    virtual QVariant data(int column, int role) const;

    // Each item offers "counts" of messages.
    // Returns counts of messages of all child items summed up.
    virtual int countOfUnreadMessages() const;
    virtual int countOfAllMessages() const;

    // This method is used to permanently
    // "remove" (or "unregister") this item.
    // This typically removes item and its
    // "children" (for example messages or child feeds)
    // from the database.
    virtual bool removeItself() {
      return false;
    }

    // Access to children.
    inline QList<FeedsModelRootItem*> childItems() const {
      return m_childItems;
    }

    // Removes all children from this item.
    // NOTE: Children are NOT freed from the memory.
    inline void clearChildren() {
      m_childItems.clear();
    }

    // Removes particular child at given index.
    // NOTE: Child is NOT freed from the memory.
    bool removeChild(int index);

    inline Kind kind() const {
      return m_kind;
    }

    // Each item has icon.
    inline QIcon icon() const {
      return m_icon;
    }

    inline void setIcon(const QIcon &icon) {
      m_icon = icon;
    }

    // Each item has some kind of id.
    inline int id() const {
      return m_id;
    }

    inline void setId(int id) {
      m_id = id;
    }

    // Each item has its title.
    // NOTE: This is note entirely true for the root item.
    inline QString title() const {
      return m_title;
    }

    inline void setTitle(const QString &title) {
      m_title = title;
    }

    inline QDateTime creationDate() const {
      return m_creationDate;
    }

    inline void setCreationDate(const QDateTime &creation_date) {
      m_creationDate = creation_date;
    }

    inline QString description() const {
      return m_description;
    }

    inline void setDescription(const QString &description) {
      m_description = description;
    }

    // Compares two model items.
    static bool isEqual(FeedsModelRootItem *lhs, FeedsModelRootItem *rhs);
    static bool lessThan(FeedsModelRootItem *lhs, FeedsModelRootItem *rhs);

  protected:
    Kind m_kind;
    int m_id;
    QString m_title;
    QString m_description;
    QIcon m_icon;
    QDateTime m_creationDate;

    QList<FeedsModelRootItem*> m_childItems;
    FeedsModelRootItem *m_parentItem;
};

#endif // FEEDMODELROOTITEM_H
