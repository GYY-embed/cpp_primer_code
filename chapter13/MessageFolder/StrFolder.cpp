#include <utility>
#include <iostream>
using std::cerr; using std::endl;

#include <set>
using std::set; 

#include "StrFolder.h"

void swap(Message &lhs, Message &rhs)
{
        using std::swap;

        for(auto f = lhs.folders.begin(); f != lhs.folders.end(); ++f)
                (*f) -> remMsg(&lhs);
        for(auto f = rhs.folders.begin(); f != rhs.folders.end(); ++f)
                (*f) -> remMsg(&rhs);
        
        swap(lhs.folders, rhs.folders);
        swap(lhs.contents, rhs.contents);

        for(auto f = lhs.folders.begin(); f != lhs.folders.end(); ++f)
                (*f) -> addMsg(&lhs);
        for(auto f = rhs.folders.begin(); f != rhs.folders.end(); ++f)
                (*f) -> addMsg(&rhs);
}

Message::Message(const Message &m) : 
        contents(m.contents), folders(m.folders)
{
        add_to_Folders(m);
}

Message &Message::operator=(const Message &m)
{
        remove_from_Folders();
        contents = m.contents;
        folders = m.folders;
        add_to_Folders(m);
        return *this;
}

Message::~Message()
{
        remove_from_Folders();
}

void Message::add_to_Folders(const Message &m)
{
        for(auto f = m.folders.begin(); f != m.folders.end(); ++f)
                (*f) -> addMsg(this);
}

void Message::remove_from_Folders()
{
        for(auto f = folders.begin(); f != folders.end(); ++f)
                (*f) -> remMsg(this);
        folders.clear();
}

void Message::save(Folder &f)
{
        folders.insert(&f);
        f.addMsg(this);
}

void Message::remove(Folder &f)
{
        folders.erase(&f);
        f.remMsg(this);
}

Folder::Folder(const Folder &f) : msgs(f.msgs)
{
        add_to_Message(f);
}

Folder &Folder::operator=(const Folder &f)
{
        remove_from_Message();
        msgs = f.msgs;
        add_to_Message(f);
        return *this;
}

Folder::~Folder()
{
        remove_from_Message();
}

void Folder::save(Message &m)
{
        msgs.insert(&m);
        m.addFldr(this);
}

void Folder::remove(Message &m)
{
        msgs.erase(&m);
        m.addFldr(this);
}

void Folder::add_to_Message(const Folder &f)
{
       for(auto msg = f.msgs.begin(); msg  != f.msgs.end(); ++msg)
                (*msg) -> addFldr(this); 
}

void Folder::remove_from_Message()
{
        while(!msgs.empty())
                (*msgs.begin()) -> remove(*this);
}

void Message::debug_print()
{
        cerr << "Message: \n\t" << contents << endl;
        cerr << "Appears in " << folders.size() << "Folders" << endl;
}

void Folder::debug_print()
{
        cerr << "Folders contains " << msgs.size() << " messages" << endl;
        int ctr = 1;
        for(auto m = msgs.begin(); m != msgs.end(); ++m)
        {
                cerr << "Message " << ctr++ << ":\n\t" << (*m )->contents <<endl;
        }
}

