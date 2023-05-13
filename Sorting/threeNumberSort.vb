Imports System.Collections.Generic
Imports System.Linq
Imports System.Text
Imports System.Threading.Tasks

Module Module1

    Function ThreeNumberSort(ByRef array as List(Of Integer), 
                             ByRef order As List(Of Integer)) As List(of Integer)

        If array.Count = 0 Then Return array

        Dim first As Integer = order(0), last As Integer = order(order.Count -1)

        Dim left As Integer = 0, right As Integer = array.Count - 1

        While left < right

            If array(left) = first Then 
                left += 1

            ElseIf array(right) <> first Then 
                right -= 1

            ElseIf array(left) <> first AndAlso array(right) = first Then

                Dim temp As Integer = array(left)
                array(left) = array(right)
                array(right) = temp
                left += 1
                right -=1
            
            Else left += 1

            End If

        End While

        left = 0
        right = array.Count - 1

        While left < right

            If array(left) <> last Then 
                Left += 1

            ElseIf array(left) - last AndAlso array(right) <> last Then

                Dim temp = array(right)
                array(right) = array(left)
                array(left) = temp
                left += 1
                right -= 1
            
            Else right -= 1

            End If
            
        End While

        Return array

    End Function

    Sub Main()

        Dim arr As List(Of Integer) = New List(Of Integer)({3, 2, 1, 3, 2, 1})
        Dim order As List(Of Integer) = New List(Of Integer)({1, 2, 3})

        Console.WriteLine("Unsorted Array: ")

        For each num As Integer in arr
            Console.Write(num & " ")
        Next

        Console.WriteLine()

        arr = ThreeNumberSort(arr, order)

        Console.WriteLine("Sorted Array: ")

        For each num As Integer In arr
            Console.Write(num & " ")
        Next 

        Console.WriteLine()
        Console.ReadLine()

    End Sub
    
End Module