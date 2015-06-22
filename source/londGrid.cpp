#include "londGrid.h"
#include "arquitetura.h"

enum Columns
{
	Col_pos,
	Col_data,
	Col_Max
};

static const wxChar *headers[Col_Max] =
{
    _T("Posição"),
    _T("Dado"),
};

wxString londGrid::GetTypeName(int WXUNUSED(row), int col)
{
    switch ( col )
    {
        case Col_pos:
			return wxGRID_VALUE_STRING;
		case Col_data:
            /*
		case Col_Id:
        case Col_Priority:
            return wxGRID_VALUE_NUMBER;;

        case Col_Severity:
            // fall thorugh (TODO should be a list)

        case Col_Summary:
            return wxString::Format(_T("%s:80"), wxGRID_VALUE_STRING);

        case Col_Platform:
            return wxString::Format(_T("%s:all,MSW,GTK,other"), wxGRID_VALUE_CHOICE);

        case Col_Opened:
            return wxGRID_VALUE_BOOL;*/
            return wxGRID_VALUE_STRING;
    }

    wxFAIL_MSG(_T("unknown column"));

    return wxEmptyString;
}

int londGrid::GetNumberRows()
{
    return MAXMEM;
}

int londGrid::GetNumberCols()
{
    return Col_Max;
}

bool londGrid::IsEmptyCell( int row, int col )
{
    if ( row > GetNumberRows() || row < 0 || col > GetNumberCols() || col < 0 )
    {
		wxFAIL_MSG(_T("unexpected cell."));
		return true;
    }
    return false;
}

wxString londGrid::GetValue( int row, int col )
{
    switch ( col )
    {
        case Col_pos:
            return wxString::Format(_T("%04X"), row).Right(4);

        case Col_data:
            return wxString::Format(_T("%04X"), mem[row]).Right(4);
    }

    return wxEmptyString;
}

void londGrid::SetValue( int row, int col, const wxString& value )
{
    switch ( col )
    {
        case Col_pos:
            wxFAIL_MSG(_T("unexpected column"));
            break;

        case Col_data:
			{
				long temp;
				value.ToLong(&temp, 0);
				mem[row] = temp;
			}
            break;
    }
}

bool londGrid::CanGetValueAs(int WXUNUSED(row),
                             int col,
                             const wxString& typeName)
{
    if ( typeName == wxGRID_VALUE_STRING )
    {
        return true;
    }
    else if ( typeName == wxGRID_VALUE_NUMBER )
    {
		return true;
    }
    else
    {
        return false;
    }
}

bool londGrid::CanSetValueAs( int row, int col, const wxString& typeName )
{
    return CanGetValueAs(row, col, typeName);
}

long londGrid::GetValueAsLong( int row, int col )
{
    switch ( col )
    {
        case Col_pos:
            return row;

        case Col_data:
            return mem[row];

        default:
            wxFAIL_MSG(_T("unexpected column"));
            return -1;
    }
}

bool londGrid::GetValueAsBool( int row, int col )
{
	wxFAIL_MSG(_T("unexpected column"));
	return false;
}

void londGrid::SetValueAsLong( int row, int col, long value )
{
    switch ( col )
    {
        case Col_data:
            mem[row] = value;
            break;

        default:
            wxFAIL_MSG(_T("unexpected column"));
    }
}

void londGrid::SetValueAsBool( int row, int col, bool value )
{
    wxFAIL_MSG(_T("unexpected column"));
}

wxString londGrid::GetColLabelValue( int col )
{
	if ( col > Col_Max )
	{
		return "bogus";
	}
    return headers[col];
}
