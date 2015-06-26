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

#ifndef __gui_mrview_tool_connectome_node_list_model_h__
#define __gui_mrview_tool_connectome_node_list_model_h__

#include <QAbstractItemModel>


namespace MR
{
  namespace GUI
  {
    namespace MRView
    {
      namespace Tool
      {


        class Connectome;


        class Node_list_model : public QAbstractItemModel
        {
          public:

            Node_list_model (Connectome* parent);

            QVariant data (const QModelIndex& index, int role) const override;
            QVariant headerData (int section, Qt::Orientation orientation, int role) const override;

            Qt::ItemFlags flags (const QModelIndex& index) const override {
              if (!index.isValid()) return 0;
              return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
            }

            QModelIndex parent (const QModelIndex&) const override {
              return QModelIndex(); 
            }

            int rowCount (const QModelIndex& parent = QModelIndex()) const override;
            int columnCount (const QModelIndex& parent = QModelIndex()) const override;

            QModelIndex index (int row, int column, const QModelIndex& parent = QModelIndex()) const {
              (void ) parent;
              return createIndex (row, column);
            }

            void clear()
            {
              beginRemoveRows (QModelIndex(), 0, rowCount()-1);
              endRemoveRows();
            }

            void initialize()
            {
              beginInsertRows (QModelIndex(), 0, rowCount()-1);
              endInsertRows();
            }

          private:
            Connectome& connectome;
        };


      }
    }
  }
}

#endif



