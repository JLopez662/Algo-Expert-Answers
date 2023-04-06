Imports System.Collections.Generic 

Module Module1

    Function SortedSquaredArray(array As List(Of Integer)) As List(Of Integer)
        
        Dim start As Integer = 0
        Dim [end] As Integer = array.Count -1
        Dim sorted As New List(Of Integer)

        For Each num As Integer In array
            sorted.Add(Math.Pow(num, 2))
        Next 

        While start<> [end]
            If sorted(start) >= sorted([end]) Then 

                sorted.Add(sorted(start))
                start += 1
            
            Else
                sorted.Add(sorted([end]))
                [end] -= 1
            End If
        End While

        sorted.Reverse()

        Return sorted
    End Function

    Sub Main()
        
        Dim array As New List(Of Integer) From {1, 2, 3, 5, 6}

        Dim result As List (Of Integer) = SortedSquaredArray(array)

        Console.WriteLine("Result: " & String.Join(", ", result))
    End Sub
    
End Module