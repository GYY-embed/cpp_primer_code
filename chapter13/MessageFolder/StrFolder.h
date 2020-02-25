#ifndef __STRFOLDER_H
#define __STRFOLDER_H

#include "String.h"
#include "set"

class Folder;

class Message
{
friend void swap(Message &, Message &);
friend class Folder;
public:
        explicit Message(const String &str = ""):
                contents(str) { }
        Message(const Message &);
        Message &operator=(const Message &);
        ~Message();

        void save(Folder &);
        void remove(Folder &);
        void debug_print();
private:
        String contents;
        std::set<Folder*> folders;
        
        void add_to_Folders(const Message &);
        void remove_from_Folders();

        void addFldr(Folder *f) { folders.insert(f); }
        void remFldr(Folder *f) { folders.erase(f); }
};

void swap(Message &, Message &);

class Folder
{
friend void swap(Message &,Message &);
friend class Message;
public:
        ~Folder();
        Folder(const Folder &);
        Folder &operator=(const Folder &);

        Folder() {}
        void save(Message &);
        void remove(Message &);
        void debug_print();
private:
        std::set<Message*> msgs;
        void add_to_Message(const Folder &);
        void remove_from_Message();
        void addMsg(Message *m) { msgs.insert(m); }
        void remMsg(Message *m) { msgs.erase(m); }
};

#endif 