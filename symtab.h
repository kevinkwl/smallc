//
// Created by Kevin Ling on 07/01/2017.
//

#ifndef SMALLC_SEMANT_H
#define SMALLC_SEMANT_H
#include "def.h"


//
// SymbolTable<DAT> describes a symbol table mapping symbols of
//    type `SYM' to data of type `DAT *'.  It is implemented as a
//    list of lists of `SymtabEntry<SYM,DAT> *'.  The inner list is
//    a scope, a mapping from symbols to data, and the outer list is
//    a list of scopes.
//
//    `tbl' points to the current top scope.
//
//    `enterscope' makes the table point to a new scope whose parent
//       is the scope it pointed to previously.
//
//    `exitscope' makes the table point to the parent scope of the
//        current scope.  Note that the old child scope is not
//        deallocated.  One may save the state of a symbol table
//        at a given point by copying it with `operator ='
//
//    `put(s,i)' adds a symbol table entry to the current scope of
//        the symbol table mapping symbol `s' to data `d'.  The old
//        top scope isn't modified; a new scope is created whose
//        entry list is the new entry followed by the old entry list,
//        and whose tail is the old top scope's parent.  The table
//        is made to point to this new scope.
//
//    `lookup(s)' looks for the symbol `s', starting at the top scope
//        and proceeding down the list of scopes until either an
//        entry is found whose `get_id()' equals `s', or the end of
//        the root scope is reached.  It returns the data item
//        associated with the entry, or NULL if no such entry exists.
//
//
//    `probe(s)' checks the top scope for an entry whose `get_id()'
//        equals `s', and returns the entry's `get_info()' if
//        found, and NULL otherwise.
//
//    `dump()' prints the symbols in the symbol table.
//

template <class DAT>
class SymbolTable
{
    using Scope = std::unordered_map<string, DAT>;
    using ScopeList = std::list<Scope>;
private:
    ScopeList  *scopes;
public:
    SymbolTable(){ scopes = new std::list<Scope>();}     // create a new symbol table

    // Create pointer to current symbol table.
    SymbolTable &operator =(const SymbolTable &s) { scopes = s.scopes; return *this; }

    void fatal_error(string msg)
    {
        cerr << msg << "\n";
        exit(1);
    }

    // Enter a new scope.  A symbol table is organized as a list of
    // lists.  The head of the list is the innermost scope, the tail
    // holds the outer scopes.  A scope must be entered before anything
    // can be added to the table.

    void enterscope()
    {
        scopes->push_front(std::unordered_map<string, DAT>());
    }

    // Pop the first scope off of the symbol table.
    void exitscope()
    {
        // It is an error to exit a scope that doesn't exist.
        if (scopes->empty()) {
            fatal_error("exitscope: Can't remove scope from an empty symbol table.");
        }
        scopes->pop_front();
    }

    // put an item to the symbol table.
    void put(string s, DAT i)
    {
        // There must be at least one scope to add a symbol.
        if (scopes->empty()) fatal_error("addid: Can't add a symbol without a scope.");

        Scope& scope = scopes->front();
        scope[s] = i;
    }

    // Lookup an item through all scopes of the symbol table.  If found
    // it returns the associated information field, if not it returns
    // NULL.

    DAT lookup(string s)
    {
        for (auto iter = scopes->cbegin(); iter != scopes->cend(); iter++) {
            auto search = iter->find(s);
            if (search != iter->end()) {
                return search->second;
            }
        }
        return NULL;
    }

    // probe the symbol table.  Check the top scope (only) for the item
    // 's'.  If found, return the information field.  If not return NULL.
    DAT probe(string s)
    {
        if (scopes->empty()) {
            fatal_error("probe: No scope in symbol table.");
        }
        Scope& current = scopes->front();
        auto search = current.find(s);
        if (search != current.end()) {
            return search->second;
        }
        return(NULL);
    }

    // Prints out the contents of the symbol table
    void dump()
    {
        for (auto pscope = scopes->cbegin(); pscope != scopes->cend(); pscope++) {
            cerr << "\nScope: ";
            for (auto & entry : *pscope)
                cerr << ' ' << entry.first;
        }
    }

};
#endif //SMALLC_SEMANT_H
