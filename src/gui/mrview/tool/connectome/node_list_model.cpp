/*
   Copyright 2009 Brain Research Institute, Melbourne, Australia

   Written by Robert E. Smith, 2015.

   This file is part of MRtrix.

   MRtrix is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   MRtrix is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with MRtrix.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "gui/mrview/tool/connectome/node_list_model.h"

#include "gui/mrview/tool/connectome/connectome.h"

namespace MR
{
  namespace GUI
  {
    namespace MRView
    {
      namespace Tool
      {



      Node_list_model::Node_list_model (Connectome* parent) :
          QAbstractItemModel (dynamic_cast<QObject*>(parent)),
          connectome (*parent) { }



      QVariant Node_list_model::data (const QModelIndex& index, int role) const
      {
        if (!index.isValid()) return QVariant();
        if (role != Qt::DisplayRole) return QVariant();
        if (index.column() == 0)
          return str(index.row()+1).c_str();
        else
          return connectome.nodes[index.row()+1].get_name().c_str();
      }

      QVariant Node_list_model::headerData (int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const
      {
        if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
          return QVariant();
        switch (section) {
          case 0: return "Index";
          case 1: return "Name";
          default: assert (0); return "";
        }
      }



      int Node_list_model::rowCount (const QModelIndex& parent) const
      {
        (void) parent;  // to suppress warnings about unused parameters
        return (connectome.num_nodes() ? connectome.num_nodes() : 0);
      }
      int Node_list_model::columnCount (const QModelIndex& parent) const
      {
        (void) parent; // to suppress warnings about unused parameters
        return 2;
      }



      }
    }
  }
}



