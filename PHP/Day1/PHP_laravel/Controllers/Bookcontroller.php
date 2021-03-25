<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class Bookcontroller extends Controller
{
    public function english(){
        $English = [
            'Harry Poter',
            'Tom and Jerry',
            'Dr.gikill and Hide'
        ];
        return view('contact',[
            'Englishs' => $English
        ]);
    }

    public function korean(){
        $korean = [
            '동백꽃',
            '파수꾼',
            '치부'
        ];
        return view('hello',[
            'koreans' => $korean
        ]);
    }

}
