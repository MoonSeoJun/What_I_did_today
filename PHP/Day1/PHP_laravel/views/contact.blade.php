@extends('layout')

@section('title')
    English Library
@endsection

@section('content')
    Here is English
    <ul>
        @foreach($Englishs as $English)
            <li>{{ $English }}</li>
        @endforeach
    </ul>
@endsection
